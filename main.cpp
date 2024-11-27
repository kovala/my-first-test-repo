#include <array>
#include <iostream>
#include <vector>
#include <argh.h>
#include <chrono>
#include <mitata.hpp>
#include <fmt/color.h>
#include <fmt/ranges.h>
#include <random>

#include <utils.h>
#include <algo.h>

void testJson(const std::vector<int>& v) {
  json j = {
    {"happy", 1},
    {"vecy", v},
  };
  std::cout << j << std::endl;
}
void testMe(const std::vector<int>& v) {
  for (const auto& a: v) {
    std::cout << "v" << a << std::endl;
  }
}

void testSort() {
  std::array<int, 3> a = {2, 1, 3};
  std::ranges::sort(a);
  u::jlog({"arr", a});
}
std::function<void()> gFn;
void helperFn() {
  if (gFn) gFn();
}

std::map<std::string, std::function<void()>> m = {
  {"stdarr", [] {
    std::array sarr = {5, 6, 56, 456, 456, 546, 456};
    auto arr = {5, 6, 56, 456, 456, 546, 456};
    u::jlog({"arr", arr, "sarr", sarr});
  }},
  {"vec", [] {
    testMe({100, 333, 666});
    testSort();
  }},
  {"arrays", [] {
    auto result = arrays::binarySearch({1, 2, 3, 4, 5, 6, 7}, 3);
    u::jlog({{"result", result}});
  }},
  {"group-anagrams", [] {
    auto result = arrays::groupAnagramsOptimal({"act","pots","tops","cat","stop","hat"});
    u::jlog({{"result", result}});
  }},

  {"benchmark:binary-search", [] {
    mitata::runner runner;

    int big = 1'000'000;
    auto vec = utils::genRandomIntArray(big, 1, big);
    std::ranges::sort(vec);
    fmt::print(fg(fmt::color::yellow), "inputArray: {}\n",  std::vector(vec.begin(), vec.begin() + std::min(size_t(100), vec.size())));

    gFn = [&] { arrays::twoSum(vec, big); };
    runner.summary([&] {
      // runner.bench("empty fn", [] { });
      runner.bench("binarySearch", helperFn);
    });
    auto stats = runner.run();
  }},
  {"benchmark:twosum", [] {
    mitata::runner runner;

    int big = 1'000'000;
    auto vec = utils::genRandomIntArray(big, 1, big);
    fmt::print(fg(fmt::color::yellow), "inputArray: {}\n",  std::vector<int>(vec.begin(), vec.begin() + std::min(size_t(100), vec.size())));

    gFn = [&] { arrays::twoSum(vec, big); };

    runner.summary([&] {
      runner.bench("twoSum", helperFn);
    });
    auto stats = runner.run();
  }},
  {"benchmark:has-duplicate", [] {
    mitata::runner runner;

    int big = 1'000'000;
    auto vec = utils::genRandomIntArray(big, 1, big);
    fmt::print(fg(fmt::color::yellow), "inputArray: {}\n",  std::vector<int>(vec.begin(), vec.begin() + std::min(size_t(100), vec.size())));

    gFn = [&] { arrays::hasDuplicateOptimal(vec); };

    runner.summary([&] {
      runner.bench("has-duplicate", helperFn);
    });
    auto stats = runner.run();
  }},
  {"benchmark:group-anagrams", [] {
    mitata::runner runner;

    int big = 1'00'000;
    auto vec = utils::genRandomStrArray(big, 1, 100);
    fmt::print(fg(fmt::color::yellow), "inputArray: {}\n",  std::vector(vec.begin(), vec.begin() + std::min(size_t(10), vec.size())));

    gFn = [&] { arrays::groupAnagramsOptimal(vec); };
    runner.summary([&] {
      runner.bench("group-anagrams", helperFn);
    });
    auto stats = runner.run();
  }},
};

int main(int n, const char* args[]) {
  argh::parser cli(args);
  u::jlog({"flags", cli.flags()});

  for (auto& f: cli.flags()) {
    if (m.contains(f)) {
      m[f]();
    }
  }
  return 0;
}
