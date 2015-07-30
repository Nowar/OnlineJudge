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
  std::string Input, CardStr;
  while (std::getline(is, Input)) {
    std::stringstream ss;
    ss << Input;

    Player PlayerB, PlayerW;
    for (int i = 0; i < 5; ++i) {
      ss >> CardStr;
      PlayerB.appendCard(CardStr);
    }
    for (int i = 0; i < 5; ++i) {
      ss >> CardStr;
      PlayerW.appendCard(CardStr);
    }
    
    Player::compareAndPrintResult(PlayerB, "Black wins.",
                                  PlayerW, "White wins.",
                                  "Tie.");
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
