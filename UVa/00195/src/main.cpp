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
  std::string Input;
  std::getline(is, Input);
  std::vector<std::string> Results;
  Results.reserve(100);
  while (Count-- > 0) {
    std::getline(is, Input);
    std::sort(ALL(Input));
    do {
      Results.push_back(Input);
    } while (std::next_permutation(ALL(Input)));
    std::sort(ALL(Results), [](const std::string &A, const std::string &B) -> bool {
                UASSERT (A.size() == B.size());
                REP (i, 0, A.size()) {
                  if (A[i] % 32 != B[i] % 32)  return A[i] % 32 < B[i] % 32;
                  else if (A[i] != B[i])  return  A[i] < B[i];
                }
                return false;
              });
    for (auto S : Results)
      os << S << "\n";
    Results.clear();
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
