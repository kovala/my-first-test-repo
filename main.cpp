#include <array>
#include <iostream>
#include <vector>
#include <argh.h>
#include <chrono>
#include <mitata.hpp>

#include <util.h>
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
    runner.summary([&]() {
      runner.bench("empty fn", []() { });
      runner.bench("binarySearch", [] { arrays::binarySearch({1, 2, 3, 4, 5, 6, 7}, 3); });
    });
    auto stats = runner.run();
  }},
//  {"fmt", [] { Lits::println(); }},
//  {"sp", [] {
//    Vigur::variaDick();
//    Vigur::customDeleters();
//    Vigur::advanceSharedPointers();
//    Vigur::sharedPointers();
//  }},
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
