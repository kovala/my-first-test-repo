#include <algo.h>

namespace arrays {
  int binarySearch(const std::vector<int>& sortedArr, int target) {
    for (int left = 0, right = sortedArr.size() - 1; left <= right;) {
      auto mid = (left + right)/2;

      if (sortedArr[mid] == target) {
        return mid;
      } else if (sortedArr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
}
