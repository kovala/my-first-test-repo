export const genRandomArray = (length: number, min: number = 0, max: number = 1): number[] =>
  Array.from({length}, () => Math.random() * (max - min) + min);

export const genRandomIntArray = (length: number, min: number = 0, max: number = 1): number[] =>
  Array.from({length}, () => Math.floor(Math.random() * (max - min) + min));