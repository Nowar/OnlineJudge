//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//
#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <vector>
#include <queue>
#include <utility>

// white -> big char ->  bottom to up
// black -> small char -> top to down

// Pawn（士兵，以p或P表示）一次只能往前走一步，但是攻擊時卻是往左前方或右前方一格攻擊。
// Knight（騎士，以n或N表示）走法比較特別，是走L形的，像中國象棋的馬，參考下面的圖。
// Bishop（主教，以b或B表示）可以走對角線任意格。
// Rook（城堡，以r或R表示）可以走直線任意格。
// Queen（皇后，以q或Q表示）可以走對角線及直線任意格。像Bishop及Rook的綜合體。
// King（國王，以k或K表示）可以走前後左右及對角線一格。

static const int kMax = 8;    // 0-7 matrix
char Table[kMax][kMax];
static int BR = 0;  // Black Row
static int BC = 0;
static int WR = 0;
static int WC = 0;  // White Col

int checkOnPawn() {
  int i = WR-1, j = WC-1;
  if (i >= 0 && j >= 0 && Table[i][j] == 'p')
    return -1;
  i = WR-1; j = WC+1;
  if (i >= 0 && j <= 7 && Table[i][j] == 'p')
    return -1;

  i = BR+1; j = BC-1;
  if (i <= 7 && j >= 0 && Table[i][j] == 'P')
    return 1;
  i = BR+1; j = BC+1;
  if (i <= 7 && j <= 7 && Table[i][j] == 'P')
    return 1;

  return 0;
}

int checkOnKnight() {
  int i = WR-1, j = WC-2;
  if (i >= 0 && j >= 0 && Table[i][j] == 'n')
    return -1;
  i = WR-2; j = WC-1;
  if (i >= 0 && j >= 0 && Table[i][j] == 'n')
    return -1;
  i = WR-1, j = WC+2;
  if (i >= 0 && j <= 7 && Table[i][j] == 'n')
    return -1;
  i = WR-2, j = WC+1;
  if (i >= 0 && j <= 7 && Table[i][j] == 'n')
    return -1;
  i = WR+1; j = WC-2;
  if (i <= 7 && j >= 0 && Table[i][j] == 'n')
    return -1;
  i = WR+2; j = WC-1;
  if (i <= 7 && j >= 0 && Table[i][j] == 'n')
    return -1;
  i = WR+1; j = WC+2;
  if (i <= 7 && j <= 7 && Table[i][j] == 'n')
    return -1;
  i = WR+2; j = WC+1;
  if (i <= 7 && j <= 7 && Table[i][j] == 'n')
    return -1;

  i = BR-1; j = BC-2;
  if (i >= 0 && j >= 0 && Table[i][j] == 'N')
    return 1;
  i = BR-2; j = BC-1;
  if (i >= 0 && j >= 0 && Table[i][j] == 'N')
    return 1;
  i = BR-1, j = BC+2;
  if (i >= 0 && j <= 7 && Table[i][j] == 'N')
    return 1;
  i = BR-2, j = BC+1;
  if (i >= 0 && j <= 7 && Table[i][j] == 'N')
    return 1;
  i = BR+1; j = BC-2;
  if (i <= 7 && j >= 0 && Table[i][j] == 'N')
    return 1;
  i = BR+2; j = BC-1;
  if (i <= 7 && j >= 0 && Table[i][j] == 'N')
    return 1;
  i = BR+1; j = BC+2;
  if (i <= 7 && j <= 7 && Table[i][j] == 'N')
    return 1;
  i = BR+2; j = BC+1;
  if (i <= 7 && j <= 7 && Table[i][j] == 'N')
    return 1;

  return 0;
}

int checkOnBishopOrQueen() {
  int i, j;
  i = WR-1; j = WC-1;
  for ( ; i >= 0 && j >= 0; --i, --j) {
    if (Table[i][j] == 'b' || Table[i][j] == 'q')
      return -1;
    else if (Table[i][j] != '.')
      break;
  }
  i = WR-1; j = WC+1;
  for ( ; i >= 0 && j <= 7; --i, ++j) {
    if (Table[i][j] == 'b' || Table[i][j] == 'q')
      return -1;
    else if (Table[i][j] != '.')
      break;
  }
  i = WR+1; j = WC-1;
  for ( ; i <= 7 && j >= 0; ++i, --j) {
    if (Table[i][j] == 'b' || Table[i][j] == 'q')
      return -1;
    else if (Table[i][j] != '.')
      break;
  }
  i = WR+1; j = WC+1;
  for ( ; i <= 7 && j <= 7; ++i, ++j) {
    if (Table[i][j] == 'b' || Table[i][j] == 'q')
      return -1;
    else if (Table[i][j] != '.')
      break;
  }

  i = BR-1; j = BC-1;
  for ( ; i >= 0 && j >= 0; --i, --j) {
    if (Table[i][j] == 'B' || Table[i][j] == 'Q')
      return 1;
    else if (Table[i][j] != '.')
      break;
  }
  i = BR-1; j = BC+1;
  for ( ; i >= 0 && j <= 7; --i, ++j) {
    if (Table[i][j] == 'B' || Table[i][j] == 'Q')
      return 1;
    else if (Table[i][j] != '.')
      break;
  }
  i = BR+1; j = BC-1;
  for ( ; i <= 7 && j >= 0; ++i, --j) {
    if (Table[i][j] == 'B' || Table[i][j] == 'Q')
      return 1;
    else if (Table[i][j] != '.')
      break;
  }
  i = BR+1; j = BC+1;
  for ( ; i <= 7 && j <= 7; ++i, ++j) {
    if (Table[i][j] == 'B' || Table[i][j] == 'Q')
      return 1;
    else if (Table[i][j] != '.')
      break;
  }

  return 0;
}

int checkOnRookOrQueen() {
  int i, j;
  i = WR-1, j = WC;
  for ( ; i >= 0; --i) {
    if (Table[i][j] == 'r' || Table[i][j] == 'q')
      return -1;
    else if (Table[i][j] != '.')
      break;
  }
  i = WR, j = WC-1;
  for ( ; j >= 0; --j) {
    if (Table[i][j] == 'r' || Table[i][j] == 'q')
      return -1;
    else if (Table[i][j] != '.')
      break;
  }
  i = WR+1, j = WC;
  for ( ; i <= 7; ++i) {
    if (Table[i][j] == 'r' || Table[i][j] == 'q')
      return -1;
    else if (Table[i][j] != '.')
      break;
  }
  i = WR, j = WC+1;
  for ( ; j <= 7; ++j) {
    if (Table[i][j] == 'r' || Table[i][j] == 'q')
      return -1;
    else if (Table[i][j] != '.')
      break;
  }

  i = BR-1, j = BC;
  for ( ; i >= 0; --i) {
    if (Table[i][j] == 'R' || Table[i][j] == 'Q')
      return 1;
    else if (Table[i][j] != '.')
      break;
  }
  i = BR, j = BC-1;
  for ( ; j >= 0; --j) {
    if (Table[i][j] == 'R' || Table[i][j] == 'Q')
      return 1;
    else if (Table[i][j] != '.')
      break;
  }
  i = BR+1, j = BC;
  for ( ; i <= 7; ++i) {
    if (Table[i][j] == 'R' || Table[i][j] == 'Q')
      return 1;
    else if (Table[i][j] != '.')
      break;
  }
  i = BR, j = BC+1;
  for ( ; j <= 7; ++j) {
    if (Table[i][j] == 'R' || Table[i][j] == 'Q')
      return 1;
    else if (Table[i][j] != '.')
      break;
  }

  return 0;
}

// back check: 1
// white check: -1
// no check: 0
int check() {
  int result = checkOnPawn();
  if (result != 0)
    return result;

  result = checkOnKnight();
  if (result != 0)
    return result;

  result = checkOnBishopOrQueen();
  if (result != 0)
    return result;

  result = checkOnRookOrQueen();
  if (result != 0)
    return result;

  return 0;
}

int main() {
  std::string Input;
  int GameID = 1;
  while (true) {
    for (int i = 0; i < kMax; ++i) {
      std::getline(std::cin, Input);
      memcpy(Table[i], Input.c_str(), kMax);
      size_t PosWK = Input.find('K');
      size_t PosBK = Input.find('k');
      if (PosWK != std::string::npos) {
        WR = i;
        WC = PosWK;
      }
      if (PosBK != std::string::npos) {
        BR = i;
        BC = PosBK;
      }
    }

    bool ExitStatus = true;
    for (int i = 0 ; i < kMax; ++i) {
      for (int j = 0; j < kMax; ++j) {
        if (Table[i][j] != '.') {
          ExitStatus = false;
          break;
        }
      }
    }
    if (ExitStatus)
      break;

    int result = check();
    if (result > 0)
      std::cout << "Game #" << GameID++ << ": black king is in check.\n";
    else if (result < 0)
      std::cout << "Game #" << GameID++ << ": white king is in check.\n";
    else
      std::cout << "Game #" << GameID++ << ": no king is in check.\n";

    std::getline(std::cin, Input);
  }
  return 0;
}
