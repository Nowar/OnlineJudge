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
  int A, B, C, N; // 1 <= A, B, C <= 10000, N < 20
  is >> N;
  while (N-- > 0) {
    is >> A >> B >> C;
    int medium = static_cast<int>(std::sqrt(C/3+1)) + 1;
    bool Solved = false;
    REP (i, -medium, medium+1) {
      int remj = C-i*i;
      if (remj < 0)
        continue;
      int next_medium = static_cast<int>(std::sqrt(((remj)/2)+1)) + 1;
      REP (j, -next_medium, next_medium+1) {
        int remk = C-i*i-j*j;
        int tmpk = std::sqrt(remk);
        if (tmpk*tmpk != remk)
          continue;

        int k = -tmpk;
        if (i != j && j != k && i != k &&
            i+j+k == A &&
            i*j*k == B) {
          os << i << " " << j << " " << k << "\n";
          Solved = true;
          break;
        }

        k = tmpk;
        if (i != j && j != k && i != k &&
            i+j+k == A &&
            i*j*k == B) {
          os << i << " " << j << " " << k << "\n";
          Solved = true;
          break;
        }
      }
      if (Solved)
        break;
    }

    if (!Solved)
      os << "No solution.\n";
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
