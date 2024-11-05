#include <array>
#include <iostream>
#include <vector>
#include <argh.h>

#include <util.h>
#include <algo.h>

const std::string port1 = "8811";
const std::string port2 = "8812";

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

  }},
//  {"lits", [] {
//    Lits::initializerList();
//    Lits::randomArr();
//    Lits::routines();
//  }},
//  {"fmt", [] { Lits::println(); }},
//  {"niit", [] {
//    Niit::packagedTask();
//    Niit::once();
//    Niit::simple();
//    Niit::threadLocal();
//    Niit::atomic();
//    Niit::spinLock();
//    Niit::featureSimple();
//    Niit::featureCplex();
//    Niit::mutex();
//    Niit::sharedTimedMutex();
//    Niit::locks();
//    Niit::semaphore();
//    Niit::stopSource();
//    Niit::stopSourceAuto();
//    Niit::latch();
//    Niit::barrier();
//  }},
//  {"sp", [] {
//    Vigur::variaDick();
//    Vigur::customDeleters();
//    Vigur::advanceSharedPointers();
//    Vigur::sharedPointers();
//  }},
//  {"noob", [] {
//    Noob::moveIt();
//    Noob::checkInit();
//    Noob::basicStruct();
//    Noob::loopMaps();
//    Noob::mapsAndSets();
//    Noob::knowAlgos();
//    Noob::range();
//    Noob::nameSpace();
//  }}
};

int main(int n, const char* args[]) {
//  argh::parser cli(args);
//  u::jlog({"flags", cli.flags()});
//
//  std::cout << "hello!" << std::endl;
//
//  for (auto& f: cli.flags()) {
//    if (m.contains(f)) {
//      m[f]();
//    }
//  }
  return 0;
}
