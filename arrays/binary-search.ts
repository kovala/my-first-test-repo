import {test, expect} from "bun:test";

const binarySearch = (sortedArr: number[], target: number) => {
  let left = 0
  let right = sortedArr.length - 1

  for (; left <= right;) {
    let mid = Math.floor((left + right) / 2)

    if (sortedArr[mid] == target) {
      return mid
    } else if (sortedArr[mid] < target) {
      right = mid + 1
    } else {
      left = mid - 1
    }
  }
}

test("binary search", () => {
  const result = binarySearch([1, 2, 3, 4, 5, 6, 7], 3)
  expect(result).toBe(2)
})
