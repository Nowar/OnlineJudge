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
  is >> Count;
  while (Count-- > 0) {
    char C;
    int M, N; // 4 <= M,N <= 10
    is >> C >> M >> N;
    UASSERT (M >= 4 && N >= 4);
    UASSERT (M <= 10 && N <= 10);
    switch (C) {
    default:
      UASSERT (0);
      break;
    case 'r':
      os << std::min(M, N) << "\n";
      break;
    case 'k': {
      // Given input Big, Small
      // if (Small == 1)  return Big
      // else if (Small == 2 && Big == 2) return 4;
      // else if (Small == 2 && Big == 3) return 4;
      // else return (Big+1)/2 * (Small+1)/2 + Big/2 * Small/2;
      //
      // *** Note ***
      // The calculation order is unspecified behavior!!
      int B = std::max(M, N);
      int S = std::min(M, N);
      os << ((B+1)/2) * ((S+1)/2) + (B/2) * (S/2) << "\n";
      break;
    }
    case 'Q':
      os << std::min(M, N) << "\n";
      break;
    case 'K':
      os << ((M+1)/2) * ((N+1)/2) << "\n";
      break;
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
