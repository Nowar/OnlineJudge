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
  while (std::getline(is, Input)) {
    int count = 1;
    for (size_t i = 2; i < Input.size(); ++i) {
      if (isalpha(Input[i]) && !isalpha(Input[i-1]))  count++;
    }
    os << count << "\n";
  }
  int count;
  is >> count;
  for (int i = 0; i < count; ++i) {
    int rows;
    is >> rows;
    int sum = 0;
    for (int j = 0; j < rows; ++j) {
      int a, b, c;
      is >> a >> b >> c;
      sum += a * c;
    }
    os << sum << "\n";
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
