#include <algo.h>
#include <unordered_map>

namespace arrays {
  std::vector<int> twoSum(const std::vector<int>& arr, int target) {
    std::unordered_map<int, int> map = {};

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
