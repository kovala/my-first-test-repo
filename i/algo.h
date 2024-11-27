#pragma once
#include <vector>
#include <string>

namespace arrays {
  using strarr_t = std::vector<std::vector<std::string>>;

  int binarySearch(const std::vector<int>& sortedArr, int target);
  std::vector<int> twoSum(const std::vector<int>& arr, int target);
  bool hasDuplicateWithHashSet(const std::vector<int>& arr);
  bool hasDuplicateOptimal(const std::vector<int>& arr);
  strarr_t groupAnagramsOptimal(const std::vector<std::string>& arr);
}
