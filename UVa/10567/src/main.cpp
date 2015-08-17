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
  std::string Ref;
  std::getline(is, Ref);
  int N;
  is >> N;
  std::string Input;
  std::getline(is, Input);
  while (N-- > 0) {
    std::getline(is, Input);

    size_t InputI = 0, RefI = 0;
    size_t FirstI = Input.size();
    for (size_t InputE = Input.size(), RefE = Ref.size();
         InputI < InputE && RefI < RefE; ) {
      if (Input[InputI] == Ref[RefI]) {
        if (FirstI == InputE)
          FirstI = RefI;
        InputI++;
        RefI++;
        continue;
      }
      RefI++;
    }

    if (InputI != Input.size()) {
      os << "Not matched\n";
    } else {
      os << "Matched " << FirstI << " " << RefI-1 << "\n";
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
