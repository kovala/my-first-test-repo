import {test, expect} from "bun:test";
import {bench, run} from "mitata";
import {genRandomArray, genRandomIntArray} from "../common/utils.ts";
import {take} from "lodash"

const binarySearch = (sortedArr: number[], target: number) => {
  for (let left = 0, right = sortedArr.length - 1; left <= right;) {
    const mid = Math.floor((left + right) / 2)

    if (sortedArr[mid] == target) {
      return mid
    } else if (sortedArr[mid] < target) {
      left = mid + 1
    } else {
      right = mid - 1
    }
  }
  return -1
}

test("binary search", () => {
  const result = binarySearch([1, 2, 3, 4, 5, 6, 7], 3)
  expect(result).toBe(2)
})
test("binary search big", () => {
  const big = 1_000_000
  const bigArr = genRandomArray(big, 1, big);
  const sorted = bigArr.sort((a, b) => a - b)

  const result = binarySearch(sorted, big)
  expect(result).toBe(-1)
})

test("binary search benchmark", async () => {

  if (Bun.env['b'] == '1') {
    const big = 1_000_000
    const bigArr = genRandomIntArray(big, 1, big);
    const sorted = bigArr.sort((a, b) => a - b)

    console.log({testArray: take(sorted, 100)})

    bench('binarySearch', () => {
      binarySearch(sorted, Math.random()*big)
    });
    await run()
  }
})
