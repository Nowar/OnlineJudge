//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

int64_t Input[1000];

static int withdraw(int64_t X, int Index) {
  DEBUG (
    if (Index == 0) std::cerr << "1\n";
        );
  if (Index == 0)
    return 1;

  auto Y = Input[Index];

  DEBUG (
    if (X / Y)  std::cerr << Y << " ";
        );
  if (X / Y == 0)
    return withdraw(X, Index-1);
  else {
    X %= Y;
    if (X)
      return withdraw(X, Index-1) + 1;
    else {
      DEBUG (std::cerr << "\n");
      return 1;
    }
  }
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  int Count;
  is >> Count;
  while (Count-- > 0) {
    int N;
    is >> N;
    REP (i, 0, N)
      is >> Input[i];
    int Max = 1;
    REP (i, Input[N-1]+1, Input[N-1] << 1) {
      int Cur = withdraw(i, N-1);
      if (Cur > Max)
        Max = Cur;
    }
    os << Max << "\n";
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
