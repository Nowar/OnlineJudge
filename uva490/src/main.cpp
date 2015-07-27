//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static char Table[100][100];

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  std::fill (&Table[0][0], &Table[99][99]+1, ' ');
  std::string Input;
  int count = 0;
  int LongestSize = 0;
  while (std::getline(is, Input)) {
    memcpy(&Table[count++], Input.c_str(), Input.size());
    if (Input.size() > LongestSize) LongestSize = Input.size();
  }

  for (int j = 0; j < LongestSize; ++j) {
    for (int i = count-1; i >= 0; --i) {
      if (Table[i][j] != 0)
        os << Table[i][j];
    }
    os << "\n";
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
