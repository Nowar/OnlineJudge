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

  Item(char a, char b) : C(a), N(b) {}
};

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  bool FirstTime = true;
  while (true) {
    int Map[128] = {};
    char C;
    int MinCount = 0x7fffffff;
    int MaxCount = 0;
    while (is.read(&C, 1)) {
      if (C == '\n')  break;
      if (C >= 32 && C <= 127)  Map[C] += 1;
      MinCount = std::min(Map[C], MinCount);
      MaxCount = std::max(Map[C], MaxCount);
    }

    if (is.eof()) break;
    if (!FirstTime) os << "\n";
    REP (i, MinCount, MaxCount+1) {
      for (int j = 127; j >= 32; --j) {
        if (Map[j] == i)  os << j << " " << i << "\n";
      }
    }
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
