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
  int N;
  while (is >> N, N != 0) {
    vi Nums;
    Nums.reserve(64);
    REP (i, 0, N) {
      int Input;
      is >> Input;
      if (Input != 0)
        Nums.push_back(Input);
    }

    if (Nums.empty()) {
      os << "0\n";
      continue;
    }

    ITERATOR_REP (i, e, Nums) {
      os << *i;
      if (i+1 != e)
        os << " ";
    }
    os << "\n";
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
