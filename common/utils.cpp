#include <util.h>
#include <algo.h>
#include <queue>


namespace arrays {
  std::vector<int> findDuplicates(const std::vector<int>& arr) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;


    for (int i = 0; i < arr.size(); i++) {
      int k = target - arr[i];
      if (map.find(k) != map.end()) {
        // If it does, return the indices
        return {map[k], i};
      }
      map[arr[i]] = i;
    }
    return {};
  }
}
