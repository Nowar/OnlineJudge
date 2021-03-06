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
    double RealK = (double) 1 / K;
    for (int64_t Y = K+1; Y != 2*K+1; ++Y) {
      double RealY = (double) 1 / Y;
      int64_t X = 1 / (RealK - RealY);
      auto Val = (X*Y) / (X+Y);
      auto Mod = (X*Y) % (X+Y);
      if (Mod == 0 && Val == K) {
        std::stringstream ss;
        ss << "1/" << K << " = 1/" << X << " + 1/" << Y;
        Result.push_back(ss.str());
        continue;
      }

      Val = ((X+1)*Y) / ((X+1)+Y);
      Mod = ((X+1)*Y) % ((X+1)+Y);
      if (Mod == 0 && Val == K) {
        std::stringstream ss;
        ss << "1/" << K << " = 1/" << X+1 << " + 1/" << Y;
        Result.push_back(ss.str());
        continue;
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
