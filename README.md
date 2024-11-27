# Algorithms in `typescript` vs `c++`

<!-- TOC -->
* [Algorithms in `typescript` vs `c++`](#algorithms-in-typescript-vs-c)
  * [About](#about)
  * [Algos](#algos)
  * [Benchmarks](#benchmarks)
    * [Binary Search](#binary-search)
    * [Group Anagrams](#group-anagrams)
<!-- TOC -->

## About

Based on leetcode, hackerank, etc

This project was created using `bun init` in bun v1.1.34. [Bun](https://bun.sh) is a fast all-in-one JavaScript runtime.
To install dependencies:

Bun is a JavaScript runtime, package manager, test runner and bundler built from scratch using the Zig programming language. 
It was designed by Jarred Sumner as a drop-in replacement for Node. js. 
Bun uses WebKit's **JavaScriptCore** as the JavaScript engine, unlike Node.

For cpp CMake and conan2 setup is used

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

Bun vs gcc13 compiled cpp code

### Binary Search

array.length=1000_000

<img src="docs/cpp-binary-search.png" width="800"/> 

for sorted array using bun 

<img src="docs/ts-binary-search.png" width="800"/>

---

![](docs/bun-vs-cpp-binary-search.png)


### Group Anagrams

arrat.length=100_000

- cpp: 48 ms
- bun: 82 ms

![](docs/group-anagrams.png)
