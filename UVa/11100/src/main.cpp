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
  int Input[10000];
  int First = true;
  while (is >> N, N != 0) {
    if (!First)
      os << "\n";

    REP (i, 0, N)
      is >> Input[i];
    std::sort(Input, Input+N);

    int Max = 0;
    int LastIdx = 0;
    REP (i, 0, N) {
      if (Input[LastIdx] != Input[i]) {
        auto Diff = i-LastIdx;
        if (Diff > Max)
          Max = Diff;
        LastIdx = i;
      }
    }
    if (N-LastIdx > Max)
      Max = N-LastIdx;

    int Col = (N + Max - 1) / Max;
    int Output[Max][Col];
    std::fill(&Output[0][0], &Output[Max-1][Col-1]+1, -1);
    int Idx = 0;
    for (int j = 0; j < Col; ++j) {
      for (int i = 0; i < Max; ++i) {
        if (Idx == N)
          goto Emit;
        Output[i][j] = Input[Idx++];
      }
    }

Emit:
    os << Max << "\n";
    REP (i, 0, Max) {
      bool OutFirst = true;
      REP (j, 0, Col) {
        if (Output[i][j] != -1) {
          if (!OutFirst)
            os << " ";
          os << Output[i][j];
          OutFirst = false;
        }
      }
      os << "\n";
    }

    First = false;
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
