//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  std::string Input;
  while (std::getline(is, Input)) {
    DEBUG (std::cerr << Input << "\n");
    int N;
    std::stringstream ss;
    ss << Input;
    ss >> N;
    if (N == 1) {
      os << "Jolly\n";
      DEBUG (std::cerr << "\n");
      continue;
    }

    UASSERT (N >= 2);

    int min = 1, max = N-1;
    int last, cur;
    ss >> last;
    int DiffCount[max];
    std::fill(DiffCount, DiffCount + max, 0);
    bool Failure = false;
    while (ss >> cur) {
      int diff = std::abs(cur-last);
      DEBUG (std::cerr << "Diff: " << diff << "\n");
      if (diff < min || diff > max) {
        Failure = true;
        break;
      }
      DiffCount[diff-min] += 1;
      last = cur;
    }
    if (Failure) {
      os << "Not jolly\n";
      DEBUG (std::cerr << "\n");
      continue;
    }
    Failure = false;
    for (int i = 0; i < max; ++i) {
      if (DiffCount[i] != 1) {
        Failure = true;
        break;
      }
    }
    os << (Failure ? "Not jolly\n" : "Jolly\n");
    DEBUG (std::cerr << "\n");
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
