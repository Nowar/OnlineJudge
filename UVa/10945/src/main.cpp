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
  std::string Input;
  while (std::getline(is, Input), Input != "DONE") {
    std::vector<char> Str;  Str.reserve(128);
    for (auto c : Input)  if (::isalpha(c)) Str.push_back(::tolower(c));
    bool isPalidrome = true;
    for (int i = 0, j = Str.size()-1; i < j; ++i, --j) {
      if (Str[i] != Str[j])  { isPalidrome = false;  break;  }
    }
    os << (isPalidrome ? "You won't be eaten!\n" : "Uh oh..\n");
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
