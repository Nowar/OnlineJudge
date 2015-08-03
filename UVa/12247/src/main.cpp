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
  bool AvailableCard[53];
  std::set<int> CardPrincess;
  std::set<int> CardPrince;

  while (true) {
    std::fill(AvailableCard, AvailableCard+53, true);
    CardPrincess.clear();
    CardPrince.clear();

    int Card;
    REP (i, 0, 3) {
      is >> Card;
      CardPrincess.insert(Card);
      AvailableCard[Card] = false;
    }
    REP (i, 0, 2) {
      is >> Card;
      CardPrince.insert(Card);
      AvailableCard[Card] = false;
    }
    if (Card == 0)  break;

    int PrinceWinCount = 0;
    REP (k, 0, 2) {
      int ACard = *CardPrince.begin();
      int BCard = 0;
      CardPrince.erase(CardPrince.begin());
      ITERATOR_REP (i, e, CardPrincess) {
        if (*i > ACard) {
          BCard = *i;
          CardPrincess.erase(i);
          break;
        }
      }
      if (!BCard) {
        PrinceWinCount++;
        BCard = *CardPrincess.begin();
        CardPrincess.erase(CardPrincess.begin());
      }
#if 0
      os << "Prince: " << ACard << ", Princess: " << BCard << "\n";
#endif
    }

    if (PrinceWinCount == 2) {
      // Any card can win
      REP (i, 1, 53) {
        if (AvailableCard[i]) {
          os << i << "\n";
          break;
        }
      }
    } else if (PrinceWinCount == 0) {
      os << "-1\n";
    } else {
      // Pick a bigger card than princess remaining number
      bool Done = false;
      int BCard = *CardPrincess.begin();
#if 0
      os << "Princess remaining: " << BCard << "\n";
#endif
      REP (i, BCard+1, 53) {
        if (AvailableCard[i]) {
          os << i << "\n";
          Done = true;
          break;
        }
      }
      if (!Done)  os << "-1\n"; // Cannot get any bigger number
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
