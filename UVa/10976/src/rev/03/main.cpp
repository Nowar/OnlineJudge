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
  int64_t K;
  while (is >> K) {
    std::vector<std::string> Result;
    Result.reserve(32);
    for (int64_t Y = K+1; Y != 2*K+1; ++Y) {
      for (int64_t X = Y; ; ++X) {
        auto Up = X*Y;
        auto Down = X+Y;
        auto Val = Up / Down;
        if (Val == K && Val * Down == Up) {
          std::stringstream ss;
          ss << "1/" << K << " = 1/" << X << " + 1/" << Y;
          Result.push_back(ss.str());
          break;
        }
        if (Val > K)
          break;
      }
    }

    os << Result.size() << "\n";
    for (const auto &S : Result)
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
