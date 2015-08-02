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
  int M, N;
  while (is >> M >> N, M != 0 || N != 0) {
    // 1 <= M, N <= 500
    if (M <= 0 || N <= 0) {
      os << "0 knights may be placed on a " << M << " row " << N << " column board.\n";
      continue;
    }

    int MaxTotal = 0;
    int B = std::max(M, N);
    int S = std::min(M, N);

    // We can observe some behaviors...
    //
    // Given input Big, Small:
    // if (Small == 1)  return Big;
    // else if (Small == 2) {
    //  if (Big == 2) return 4;   // Special case
    //  else return ((Big+1)/2)*2 // No need to care about third line,
    //                               This makes odd Big can put one more piece.
    //   return 4;
    // }
    // else return (Big+1)/2 * (Small+1)/2 + Big/2 * Small/2;
    //                            // Black - white - black - ...
    //
    // *** Note ***
    // The calculation order is unspecified behavior!!
    if (S == 1) MaxTotal = B;
    else if (S == 2) {
      if (B == 2) MaxTotal = 4;
      else  MaxTotal = ((B+1)/2)*2;
    }
    else  MaxTotal = ((B+1)/2) * ((S+1)/2) + (B/2) * (S/2);

    os << MaxTotal << " knights may be placed on a " << M << " row " << N << " column board.\n";
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
