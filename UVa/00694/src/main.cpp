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
  int64_t Input, Limit, OrigInput;
  int ID = 1;
  while (is >> Input >> Limit) {
    if (Input < 0 && Limit < 0)
      break;

    int64_t Count = 0;
    UASSERT (Input > 0);
    OrigInput = Input;
    while (Input != 1) {
      if (Input % 2)
        Input = 3 * Input + 1;
      else
        Input /= 2;

      if (Input > Limit)
        break;
      Count++;
    }
    os << "Case " << ID++ << ": A = " << OrigInput << ", limit = " << Limit;
    os << ", number of terms = " << ++Count << "\n";
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
