# Algorithms in `typescript` vs `c++`

<!-- TOC -->
* [Algorithms in `typescript` vs `c++`](#algorithms-in-typescript-vs-c)
  * [About](#about)
  * [Algos](#algos)
  * [Benchmarks](#benchmarks)
    * [Binary Search](#binary-search)
      * [Bun vs GCC Compiled `c++` for array length=1_000_000 si:joy:](#bun-vs-gcc-compiled-c-for-array-length1_000_000-sijoy-)
<!-- TOC -->

## About

Based on leetcode, hackerank, etc

This project was created using `bun init` in bun v1.1.34. [Bun](https://bun.sh) is a fast all-in-one JavaScript runtime.
To install dependencies:

Bun is a JavaScript runtime, package manager, test runner and bundler built from scratch using the Zig programming language. 
It was designed by Jarred Sumner as a drop-in replacement for Node. js. 
Bun uses WebKit's **JavaScriptCore** as the JavaScript engine, unlike Node.

```bash
curl -fsSL https://bun.sh/install | bash
```


```bash
bun install
```

To run:

```bash
bun run index.ts
```



## Algos
- Arrays and Hashing
- Two Pointers
- Sliding Window
- Binary Search
- Linked Lists
- Trees
- Heap (Priority Q)
- Graphs

## Benchmarks

### Binary Search
#### Bun vs GCC Compiled `c++` for array length=1_000_000 si:joy: 
![](docs/cpp-binary-search.png)

for sorted array using bun 

![](docs/ts-binary-search.png)

---
![](docs/bun-vs-cpp-binary-search.png)
