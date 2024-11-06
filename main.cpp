#include <array>
#include <iostream>
#include <vector>
#include <argh.h>
#include <chrono>
#include <mitata.hpp>

#include <util.h>
#include <algo.h>
#include <random>

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

std::vector<int> rndVec(size_t size, int min, int max) {
  std::mt19937 gen(std::random_device{}());
  // distribution range
  std::uniform_int_distribution<int> dist(min, max);
  std::vector<int> result(size);
  std::generate(result.begin(), result.end(), [&]() { return dist(gen);  });
  return result;
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
  {"arrays-benchmark", [] {
    mitata::runner runner;

    int big = 1'000'000;
    auto vec = rndVec(big, 1, big);
    std::ranges::sort(vec);
    gFn = [&] { arrays::twoSum(vec, big); };

    runner.summary([&] {
      runner.bench("empty fn", [] { });
      runner.bench("binarySearch", helperFn);
    });
    auto stats = runner.run();
  }},
  {"twosum-benchmark", [] {
    mitata::runner runner;

    int big = 1'000'000;
    auto vec = rndVec(big, 1, big);
    gFn = [&] { arrays::twoSum(vec, big); };

    runner.summary([&] {
      runner.bench("twoSum", helperFn);
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
