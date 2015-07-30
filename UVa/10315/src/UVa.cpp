//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

// Define and implement your data structure here.
void Player::appendCard(int i, const std::string &str) {
  int Num, Suit;
  if (isdigit(str[0])) {
    Num = str[0] - 50;
  } else {
    switch (str[0]) {
    default:
      UASSERT (0);
      break;
    case 'T':
      Num = 8;
      break;
    case 'J':
      Num = 9;
      break;
    case 'Q':
      Num = 10;
      break;
    case 'K':
      Num = 11;
      break;
    case 'A':
      Num = 12;
      break;
    }
  }

  switch (str[1]) {
  default:
    UASSERT (0);
    break;
  case 'C':
    Suit = 0;
    break;
  case 'D':
    Suit = 1;
    break;
  case 'H':
    Suit = 2;
    break;
  case 'S':
    Suit = 3;
    break;
  }

  Card[i] = Suit * 13 + Num;
  ModCard[i] = Num;
}

void Player::sort() {
  std::sort(Card, Card+5, [](int a, int b) { return a > b; });
  std::sort(ModCard, ModCard+5, [](int a, int b) { return a > b; });
}

void Player::compareAndPrintResult(const Player &A, const std::string &AWinStr,
                                   const Player &B, const std::string &BWinStr,
                                   const std::string &TieStr, std::ostream &os) {
  //DEBUG(
  //  os << "PlayerA:\n";
  //  for (auto i : A.Card) os << i << " ";
  //  os << "\n";
  //  for (auto i : A.ModCard) os << i << " ";
  //  os << "\n";

  //  os << "PlayerB:\n";
  //  for (auto i : B.Card) os << i << " ";
  //  os << "\n";
  //  for (auto i : B.ModCard) os << i << " ";
  //  os << "\n";
  //     );

  // Straight flush
  {
    int AMax = A.Card[0];
    int BMax = B.Card[0];
    int AModMax = A.ModCard[0];
    int BModMax = B.ModCard[0];

    if (AModMax >=4 && BModMax >= 4 &&
        A.Card[1] == AMax-1 && A.Card[2] == AMax-2 && A.Card[3] == AMax-3 && A.Card[4] == AMax-4 &&
        B.Card[1] == BMax-1 && B.Card[2] == BMax-2 && B.Card[3] == BMax-3 && B.Card[4] == BMax-4) {
      if (AModMax > BModMax)  os << AWinStr << "\n";
      else if (AModMax < BModMax) os << BWinStr << "\n";
      else  os << TieStr << "\n";
      return;
    }
  }
}
