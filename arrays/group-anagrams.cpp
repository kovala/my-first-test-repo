#include <algo.h>
#include <array>
#include <string>
#include <unordered_map>
#include <ranges>
#include <iostream>
#include <algorithm>

#include <fmt/color.h>
#include <fmt/ranges.h>

namespace arrays {
  template <size_t N=26> auto asKey(const std::string_view& str) {
    std::array<int, N> count{};
    for (char c : str) {
      ++count[c - 'a'];
    }

    std::string result(N, '\0');
    std::ranges::transform(count, std::back_inserter(result), [](int c) {return '0' + c;});
    return result;
  }

  strarr_t groupAnagramsOptimal(const std::vector<std::string>& arr) {
    std::unordered_map<std::string, std::vector<std::string>> m = {};
    for (const auto& a : arr) {
      auto k = asKey(a);
      if (m.contains(k)) {
        m[k].push_back(a);
      } else {
        m.insert({k, {a}});
      }
      // fmt::println("k:{} a:{}", k, a);
    }

    strarr_t result;
    std::ranges::transform(m, std::back_inserter(result), [](const auto& p) {return p.second;});
    return result;
  }
}
