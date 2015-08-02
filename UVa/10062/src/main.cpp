//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

struct Item {
  char C;
  int N;

  Item(char a, int b) : C(a), N(b) {}
};

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  std::map<char, int> InMap;
  bool FirstTime = true;
  std::string Input;
  while (std::getline(is, Input)) {
    InMap.clear();
    for (auto C : Input) {
      InMap[C] += 1;
    }
    if (!FirstTime) os << "\n";
    std::vector<Item> Map;
    Map.reserve(InMap.size());
    for (auto i = InMap.begin(), e = InMap.end(); i != e; ++i)
      Map.emplace_back(i->first, i->second);
    std::sort(ALL(Map), [](const Item &A, const Item &B) {
                if (A.N != B.N) return A.N < B.N;
                else  return A.C > B.C;
              });

    for (const auto &I : Map)
      os << (int)I.C << " " << I.N << "\n";
    FirstTime = false;
  }
  return 0;
}

int main(int argc, char **argv) noexcept {
#ifndef ONLINE_JUDGE
  assert (argc > 1 && "We expect input from argv[1] for debugging purpose.");
  std::ifstream ifs;
  ifs.open(argv[1]);
  assert (ifs.good() && "Test data cannot open.");
  std::istream &is = ifs;
#else
  std::istream &is = std::cin;
#endif

  int ret = runUVa(is, std::cout);

#ifndef ONLINE_JUDGE
  ifs.close();
#endif
  return ret;
}
