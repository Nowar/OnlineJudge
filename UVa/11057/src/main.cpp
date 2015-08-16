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
  int N, M, Input[10000];
  while (is >> N) {
    REP (i, 0, N)
      is >> Input[i];
    is >> M;

    std::sort(Input, Input+N);
    auto HighIdx = std::lower_bound(Input, Input+N, (M+1) >> 1) - Input;
    UASSERT (HighIdx != N);

    if ((M & 0x1) == 0 && HighIdx != N-1 &&
        Input[HighIdx] == (M >> 1) &&
        Input[HighIdx+1] == (M >> 1)) {
      os << "Peter should buy books whose prices are " << (M >> 1) << " and " << (M >> 1) << ".\n\n";
      continue;
    }

    UASSERT (Input[HighIdx] >= (M+1) / 2);

    auto LowIdx = 0;
    REP (i, HighIdx, N) {
      auto Val = M - Input[i];
      LowIdx = std::lower_bound(Input, Input+HighIdx, Val) - Input;
      if (LowIdx != HighIdx && Input[LowIdx] == Val) {
        HighIdx = i;
        break;
      }
    }
    UASSERT (Input[LowIdx] + Input[HighIdx] == M);
    os << "Peter should buy books whose prices are " << Input[LowIdx] << " and " << Input[HighIdx] << ".\n\n";
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
