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
  int H, M;
  std::string Input;
  while (std::getline(is, Input), Input != "0:00") {
    auto Pos = Input.find(':'); UASSERT (Pos != std::string::npos);
    std::string HStr = Input.substr(0, Pos);
    std::string MStr = Input.substr(Pos+1);

    std::stringstream ss;
    ss << HStr; ss >> H;  ss.clear();
    ss << MStr; ss >> M;

    double HDeg = 0.0, MDeg = 0.0;
    HDeg += 30.0 * H;
    HDeg += 30.0/60.0 * M;
    MDeg += 6 * M;
    double Diff = std::fabs(HDeg - MDeg);
    while (Diff >= 360.0) Diff -= 360.0;
    if (Diff > 180.0) Diff = 360.0 - Diff;
    os << std::fixed << std::setprecision(3) << Diff << "\n";
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
