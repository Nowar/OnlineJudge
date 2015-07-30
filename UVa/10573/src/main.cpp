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
  int H, U, D, F;
  while (is >> H >> U >> D >> F, H != 0) {
    double Weaken = U * (double )F / 100;
    double Height = H;
    double Now = 0.0;
    int i = 0;
    double Upper = U;
    while (++i) {
      Now += Upper;
      if (Now > Height) {
        os << "success on day " << i << "\n";
        break;
      }
      Upper -= Weaken;
      if (Upper < 0)  Upper == 0;
      Now -= D;
      if (Now < 0) {
        os << "failure on day " << i << "\n";
        break;
      }
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
