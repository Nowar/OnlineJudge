//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static bool runUVa_2(std::istream &is, std::ostream &os) noexcept {
  int N, NQ;
  is >> N >> NQ;
  if (N == 0)
    return false;
  vi Input;
  Input.assign(N, 0);
  REP (i, 0, N)
    is >> Input[i];
  REP (i, 0, NQ) {
    std::map<int, int> Freq;
    int CurI, CurJ;
    is >> CurI >> CurJ;
    int Max = 0;
    REP (j, CurI-1, CurJ) {
      Freq[Input[j]]++;
      if (Freq[Input[j]] > Max)  Max = Freq[Input[j]];
    }
    os << Max << "\n";
  }
  return true;
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  while (runUVa_2(is, os))
    continue;
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
