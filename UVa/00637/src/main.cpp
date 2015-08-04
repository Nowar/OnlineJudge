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
  int Page; // [1, 101)
  while (is >> Page, Page != 0) {
    int RH[50] = {};
    int LH[50] = {};
    int TotalPage = ((Page + 3) >> 2) << 2; // Multiple of 4
    REP (i, 0, TotalPage/2)
      RH[i] = i+1;
    REP (i, TotalPage/2, TotalPage)
      LH[TotalPage - i - 1] = i+1;

    os << "Printing order for " << Page << " pages:\n";
    for (int i = 0; i < TotalPage/2; i += 2) {
      {
        os << "Sheet " << i/2+1 << ", front: ";
        int A = LH[i];  int B = RH[i];
        if (A > Page) os << "Blank, " << B << "\n";
        else  os << A << ", " << B << "\n";
      }
      {
        int A = RH[i+1];  int B = LH[i+1];
        if (A > Page && B > Page)  continue;
        os << "Sheet " << i/2+1 << ", back : ";
        if (B > Page) os << A << ", Blank\n";
        else  os << A << ", " << B << "\n";
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
