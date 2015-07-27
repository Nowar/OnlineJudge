//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static void print(int cur, int goal, std::ostream &os) {
  if (cur > goal) {
    return;
  }
  if (cur == goal) {
    for (int i = 0; i < cur; ++i)  os << cur;
    os << "\n";
    return;
  }


  for (int i = 0; i < cur; ++i)  os << cur;
  os << "\n";
  print(cur+1, goal, os);
  for (int i = 0; i < cur; ++i)  os << cur;
  os << "\n";
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  int count;
  is >> count;
  for (int i = 0; i < count; ++i) {
    int a, f;
    is >> a >> f;
    for (int i = 0; i < f; ++i) {
      print(1, a, os);
      if (i != f-1) os << "\n";
    }
    if (i != count-1) os << "\n";
  }
  // Implement here.
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
