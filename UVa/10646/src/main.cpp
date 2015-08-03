//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

struct Card {
  char N = 0;
  char S = 0;

  Card() {}
  Card(char n, char s)
    : N(n), S(s) {}
};

std::ostream &operator<<(std::ostream &os, Card C) {
  os << C.N << C.S;
  return os;
}

static int getNumber(char c) {
  if (c == 'A' || c == 'T' || c == 'J' || c == 'Q' || c == 'K')
    return 10;
  else
    return c - 48;
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  int Count;
  is >> Count;
  REP (i, 0, Count) {
    std::string Input;
    Card Cards[27];
    Card Moved[25];
    REP (j, 0, 27) {
      is >> Input;
      Cards[j] = Card(Input[0], Input[1]);
    }
    REP (j, 0, 25) {
      is >> Input;
      Moved[j] = Card(Input[0], Input[1]);
    }

    int Y = 0;
    int Size = 27;
    REP (j, 0, 3) {
      auto X = getNumber(Cards[Size-1].N);
      Y += X;
#if 0
      os << "X Y: ";
      os << (int) X << " " << (int) Y << "\n";
#endif
      Size = Size - 1 - (10-X);
    }

    if (Y > Size) os << "Case " << i+1 << ": " << Moved[Y-Size-1] << "\n";
    else  os << "Case " << i+1 << ": " <<Cards[Y-1] << "\n";
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
