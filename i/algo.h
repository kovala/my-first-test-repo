#pragma once
#include <vector>

namespace arrays {
  int binarySearch(const std::vector<int>& sortedArr, int target);
  std::vector<int> twoSum(const std::vector<int>& arr, int target);
  bool hasDuplicateWithHashSet(const std::vector<int>& arr);
  bool hasDuplicateOptimal(const std::vector<int>& arr);
}
