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
  int REQ, COM;
  int Count = 1;
  while (is >> REQ >> COM, REQ > 0) {
    if (Count != 1) os << "\n";

    std::string Input;
    std::getline(is, Input);
    REP (i, 0, REQ) std::getline(is, Input);
    int MaxOKCount = INT_MIN;
    double MinPrice = DBL_MAX;
    std::string CompanyName;
    REP (i, 0, COM) {
      double Price;
      int OKCount;
      std::string Name;
      std::getline(is, Name);
      is >> Price >> OKCount;
      std::getline(is, Input);
      REP (j, 0, OKCount) std::getline(is, Input);

      if (OKCount > MaxOKCount) {
        MaxOKCount = OKCount;
        CompanyName = Name;
        MinPrice = Price;
      } else if (OKCount == MaxOKCount) {
        if (Price < MinPrice) {
          MinPrice = Price;
          CompanyName = Name;
        }
      }
    }
    os << "RFP #" << Count++ << "\n";
    os << CompanyName << "\n";
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
