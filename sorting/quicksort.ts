import {test} from "bun:test";
import {take} from "lodash";
import {bench, run} from "mitata";
import {genRandomIntArray} from "../common/utils.ts";

export const quicksort = (arr) => {
  if (arr.length <= 1) {
    return arr;
  }

  const mid = arr[Math.floor(arr.length/2)]

  const left = arr.filter(a=>a < mid)
  const center = arr.filter(a=>a == mid)
  const right = arr.filter(a=>a > mid)

  return [...quicksort(left), ...center, ...quicksort(right)]
}

test("quicksort search benchmark", async () => {
  if (Bun.env['b'] == '1') {
    const big = 1_00_000
    const bigArr = genRandomIntArray(big, 1, big);

    console.log({testArray: take(bigArr, 33)})

    bench('quicksort', () => {
      quicksort(bigArr)
    });
    await run()
  }
})
