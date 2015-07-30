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
  int Count;
  while (is >> Count) {
    if (Count == 0) break;
    std::string Input;
    std::getline(is , Input);
    int Max = 0x7fffffff, Total = 0;
    for (int i = 0; i < Count; ++i) {
      std::getline(is, Input);
      int Num = 0;
      for (auto c : Input)
        if (c == ' ') Num++;
      // XXX: GCC 5.1 cannot compile
      //int Num = std::count_if(Input.begin(), Input.end(), [](char c) {
      //                          return c == ' ';
      //                        });
      DEBUG (std::cerr << "Num: " << Num << "\n");
      Total += Num;
      if (Num < Max)  Max = Num;
    }
    DEBUG (std::cerr << "Max: " << Max << "\n");
    DEBUG (std::cerr << "Total: " << Total << "\n");
    os << Total - Count * Max << "\n";
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
