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
  std::string Input;
  while (std::getline(is, Input)) {
    if (Input.empty()) {
      os << "\n";
      continue;
    }

    std::stringstream ss;
    ss << Input;
    int N = 0;
    while (ss) {
      char c;
      ss >> c;
      if (ss.eof()) break;
      if (isdigit(c)) {
        N += (int)c - 48;
        continue;
      }
      if (c == 'b') c = ' ';
      if (c == '!') {
        os << "\n";
        continue;
      }
      for (int i = 0; i < N; ++i) {
        os << c;
      }
      N = 0;
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
