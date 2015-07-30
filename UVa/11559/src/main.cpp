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
    int N, B, H, W;
    std::stringstream ss;
    ss << Input;
    ss >> N >> B >> H >> W;
    int Total = B+1;
    REP (i, 0, H) {
      int P, R;
      std::getline(is, Input);
      std::stringstream ss;
      ss << Input;
      ss >> P;
      ss.clear();
      std::getline(is, Input);
      ss << Input;
      REP (j, 0, W) {
        ss >> R;
        if (R >= N  && N * P < Total) Total = N * P;
      }
    }
    if (Total == B+1) os << "stay home\n";
    else  os << Total << "\n";
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
