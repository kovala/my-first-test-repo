#include <util.h>
#include <algo.h>
#include <queue>

namespace arrays {
  std::vector<int> findDuplicates(const std::vector<int>& arr) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // for (int i = 0; i < arr.size(); i++) {
    //   int k = target - arr[i];
    //   if (minHeap.find(k) != minHeap.end()) {
    //     // If it does, return the indices
    //     return {minHeap[k], i};
    //   }
    //   minHeap[arr[i]] = i;
    // }
    return {};
  }
}
