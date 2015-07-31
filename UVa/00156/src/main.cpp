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
  std::map<std::string, int> Anagrams;
  std::vector<std::string> Remaining;
  Remaining.reserve(512);
  std::string Input;
  while (is >> Input, Input != "#") {
    std::string Lower = Input;
    std::transform(Input.begin(), Input.end(), Lower.begin(), ::tolower);
    std::sort(Lower.begin(), Lower.end());
    auto Result = Anagrams[Lower]++;
    if (Result == 0)  Remaining.push_back(Input);
  }
  std::sort(Remaining.begin(), Remaining.end());
  for (auto &S : Remaining) {
    std::string Lower = S;
    std::transform(Lower.begin(), Lower.end(), Lower.begin(), ::tolower);
    std::sort(Lower.begin(), Lower.end());
    UASSERT (Anagrams[Lower] != 0);
    if (Anagrams[Lower] == 1)
      os << S << "\n";
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
