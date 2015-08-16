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
  int Heads[20000];
  int Knights[20000];
  int NHeads, NKnights;
  while (is >> NHeads >> NKnights, NHeads != 0) {
    REP (i, 0, NHeads)
      is >> Heads[i];
    REP (i, 0, NKnights)
      is >> Knights[i];
    std::sort(Heads, Heads+NHeads);
    std::sort(Knights, Knights+NKnights);
    int Sum = 0;
    int i, j;
    for (i = 0, j = 0; i < NHeads && j < NKnights; ) {
      if (Knights[j] >= Heads[i]) {
        Sum += Knights[j];
        j++;
        i++;
      } else {
        j++;
      }
    }
    if (i == NHeads)
      os << Sum << "\n";
    else
      os << "Loowater is doomed!\n";
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
