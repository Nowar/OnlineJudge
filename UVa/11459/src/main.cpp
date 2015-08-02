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
  int Count;
  is >> Count;
  REP (i, 0, Count) {
    int NPlayer, NSnake, NRoll;
    is >> NPlayer >> NSnake >> NRoll;
    int Snakes[101] = {};
    REP (j, 0, NSnake) {
      int X, Y;
      is >> X >> Y;
      Snakes[X] = Y;
    }

    int PlayerID = 0;
    int Cur[NPlayer];
    std::fill(Cur, Cur+NPlayer, 1);
    int LastRollID = NRoll;
    REP (j, 0, NRoll) {
      int Roll;
      is >> Roll;
      Cur[PlayerID] += Roll;
      int NewPos = Snakes[Cur[PlayerID]];
      if (NewPos != 0)  Cur[PlayerID] = NewPos;
      if (Cur[PlayerID] >= 100) {
        Cur[PlayerID] = 100;
        LastRollID = j+1;
        break;
      }
      PlayerID = (PlayerID + 1) % NPlayer;
    }
    REP (j, LastRollID, NRoll) {
      int Roll;
      is >> Roll;
    }

    REP (j, 0, NPlayer) {
      os << "Position of player " << j+1 << " is " << Cur[j] << ".\n";
    }
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
