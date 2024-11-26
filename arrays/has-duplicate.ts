import {test, expect} from "bun:test";
import {bench, run} from "mitata";
import {genRandomArray} from "../common/utils.ts";

// Naive approach O(n)
const hasDuplicateWithHashSet = (nums: number[]) => {
  const seen = new Set();
  for (const num of nums) {
    if (seen.has(num)) {
      return true;
    }
    seen.add(num);
  }
  return false;
};

// just comparing set sizes
const hasDuplicateOptimal = (nums: number[]) => new Set(nums).size < nums.length

test("has duplicates naive", () => {
  const result = hasDuplicateWithHashSet([1, 7, 2, 6, 7, 3, 4, 5, 6])
  expect(result).toBeTrue()
})

test("has duplicates optimal", () => {
  const result = hasDuplicateOptimal([1, 7, 2, 6, 7, 3, 4, 5, 6])
  expect(result).toBeTrue()
})

test("benchmark: has duplicates", async () => {
  const big = 1_000_000
  const bigArr = genRandomArray(big, 1, big);

  if (Bun.env['b'] == '1') {
    bench('twoSum big', () => hasDuplicateWithHashSet(bigArr));
    bench('twoSumWithMap big', () => hasDuplicateOptimal(bigArr));

    await run()
  }
})
