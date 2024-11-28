import {expect, test} from "bun:test";

interface TreeNode {
  value: number;
  children?: TreeNode[];
}

const compareTrees = (treeA: TreeNode, treeB: TreeNode) => {
  for (let stack = [[treeA, treeB]]; stack.length > 0;) {
    const [nodeA, nodeB] = stack.pop()

    if (nodeA?.value != nodeB?.value) {
      return false;
    }
    const childrenA = nodeA?.children || [];
    const childrenB = nodeB?.children || [];
    if (childrenA.length !== childrenB.length) {
      return false;
    }

    for (let i = 0; i < childrenA.length; i++) {
      stack.push([childrenA[i], childrenB[i]])
    }
  }
  return true
}

test("compareTrees: assure both trees are equal", () => {
  const tree1: TreeNode = {
    value: 1, children: [{value: 2, children: [{value: 4}, {value: 5}]}, {value: 3}]
  }
  const tree2: TreeNode = {
    value: 1, children: [{value: 2, children: [{value: 4}, {value: 5}]}, {value: 3}]
  }

  const areEqual = compareTrees(tree1, tree2)
  expect(areEqual).toBeTruthy()
})
test("compareTrees: assure both trees are not equal", () => {
  const tree1: TreeNode = {
    value: 1, children: [{value: 2, children: [{value: 4}, {value: 5}]}, {value: 3}
    ]
  }
  const tree2: TreeNode = {
    value: 2, children: [{value: 2, children: [{value: 4}, {value: 5}]}, {value: 3}]
  }

  const areEqual = compareTrees(tree1, tree2)
  expect(areEqual).toBeFalsy()
})
