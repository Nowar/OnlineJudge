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
  int Count;
  while (is >> Count, Count != 0) {
    int N, M;
    is >> N >> M;
    REP (i, 0, Count) {
      int X, Y;
      is >> X >> Y;
      if (X == N || Y == M) os << "divisa\n";
      else if (X > N && Y > M)  os << "NE\n";
      else if (X > N && Y < M)  os << "SE\n";
      else if (X < N && Y > M)  os << "NO\n";
      else if (X < N && Y < M)  os << "SO\n";
      else  UASSERT (0);
    }
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
