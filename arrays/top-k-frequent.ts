import {test, expect} from "bun:test";
import {bench, run} from "mitata";
import {genRandomArray, MinHeap} from "../common/utils.ts";

const topKFrequent = (arr:number[], k:number) => {
  const count = arr.reduce((acc, i) => ((acc[i] = (acc[i] || 0) + 1), acc), {});
  const heap = new MinHeap<number[]>();
  for (const [num, cnt] of Object.entries(count)) {
    heap.push([+num, +cnt]);
    if (heap.size() > k) heap.pop();
  }

  const res = [];
  for (let i = 0; i < k; i++) {
    const [num, cnt] = heap.pop();
    res.push(num)
  }
  return res;
}
test("topKFrequent", () => {
  const result = topKFrequent([1,2,2,3,3,3], 2)
  expect(result).toEqual([2,3])

  const result2 = topKFrequent([7,7], 1)
  expect(result2).toEqual([7])
})

const topKFrequentBucketSort = (arr:number[], k:number) => {
  const count = arr.reduce((acc, i) => ((acc[i] = (acc[i] || 0) + 1), acc), {});

  const freq = Array.from({length: arr.length + 1}, () => []);
  for (const n in count) {
    freq[count[n]].push(parseInt(n));
  }

  const res = [];
  for (let i = freq.length - 1; i > 0; i--) {
    for (const n of freq[i]) {
      res.push(n);
      if (res.length === k) {
        return res;
      }
    }
  }
}
test("topKFrequentBucketSort", () => {
  const result = topKFrequentBucketSort([1,2,2,3,3,3], 2)
  expect(result.sort()).toEqual([2,3])

  const result2 = topKFrequentBucketSort([7,7], 1)
  expect(result2).toEqual([7])
})

test("benchmark: top k frequent elements", async () => {
  const big = 1_00_000
  const bigArr = genRandomArray(big, 1, big);

  if (Bun.env['b'] == '1') {
    bench('topKFrequent big', () => topKFrequent(bigArr, 2));
    bench('topKFrequentBucketSort big', () => topKFrequentBucketSort(bigArr, 2));

    await run()
  }
})
