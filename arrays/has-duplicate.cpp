#include <algo.h>
#include <unordered_set>

namespace arrays {
  bool hasDuplicateWithHashSet(const std::vector<int>& arr) {
    std::unordered_set<int> seen = {};

    for (int num : arr) {
      if (seen.count(num)) {
        return true;
      }
      seen.insert(num);
    }
    return false;
  }

  bool hasDuplicateOptimal(const std::vector<int>& arr) {
    return std::unordered_set<int>(arr.begin(), arr.end()).size() < arr.size();
  }
}
