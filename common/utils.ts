export class MinHeap<T> {
  heap: T[] = [];

  push(val: T) {
    this.heap.push(val);
    this.bubbleUp();
  }
  pop() {
    if (this.heap.length === 1) return this.heap.pop();
    const min = this.heap[0];
    this.heap[0] = this.heap.pop()!;
    this.bubbleDown();
    return min;
  }
  peek() {
    return this.heap[0];
  }
  size() {
    return this.heap.length;
  }
  private bubbleUp() {
    let index = this.heap.length - 1;
    while (index > 0) {
      let parentIndex = Math.floor((index - 1) / 2);
      if (this.heap[index] >= this.heap[parentIndex]) break;
      [this.heap[index], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[index]];
      index = parentIndex;
    }
  }
  private bubbleDown() {
    let index = 0;
    const length = this.heap.length;
    while (true) {
      let leftChild = 2 * index + 1;
      let rightChild = 2 * index + 2;
      let smallest = index;

      if (leftChild < length && this.heap[leftChild] < this.heap[smallest]) {
        smallest = leftChild;
      }
      if (rightChild < length && this.heap[rightChild] < this.heap[smallest]) {
        smallest = rightChild;
      }

      if (smallest === index) break;
      [this.heap[index], this.heap[smallest]] = [this.heap[smallest], this.heap[index]];
      index = smallest;
    }
  }
}

export const genRandomArray = (length: number, min: number = 0, max: number = 1): number[] =>
  Array.from({length}, () => Math.random() * (max - min) + min);

export const rndNum = (min, max) => Math.floor(Math.random() * (max - min) + min);

export const genRandomIntArray = (length: number, min: number = 0, max: number = 1): number[] =>
  Array.from({length}, () => rndNum(min,  max));

export const genRandomHash = () => (Math.random() + 1).toString(26)

export const genRandomStr = (len, chars='abcdefghijklmnopqrstuvwxyz') => [...Array(len)].map(() => chars.charAt(Math.floor(Math.random() * chars.length))).join('')

export const genRandomStrArray = (length: number, min: number = 0, max: number = 1): string[] =>
  Array.from({length}, () => genRandomStr(rndNum(min,  max)));
