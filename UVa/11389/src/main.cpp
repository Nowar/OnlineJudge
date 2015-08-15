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
  int N, D, R;
  int Morning[100];
  int Evening[100];
  while (is >> N >> D >> R, N != 0) {
    REP (i, 0, N)
      is >> Morning[i];
    REP (i, 0, N)
      is >> Evening[i];
    std::sort(Morning, Morning+N);
    std::sort(Evening, Evening+N);
    int Max = 0;
    REP (i, 0, N) {
      auto Total = Morning[i] + Evening[N-1-i] - D;
      if (Total > 0)
        Max += R * Total;
    }
    DEBUG (os << "Input: " << N << " " << D << " " << R << "\n";);
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
