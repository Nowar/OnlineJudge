//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

#define BOARD_WIDTH 8
#define REAL_WIDTH  (BOARD_WIDTH + 4)

static bool isUnderPawnAttack_1(char (&Board)[REAL_WIDTH][REAL_WIDTH], int i, int j, char C) {
  bool AttackUp = (std::tolower(C) != C);
  if (AttackUp) {
    if (Board[i+1][j-1] == C ||
        Board[i+1][j+1] == C)
      return true;
  } else {
    if (Board[i-1][j-1] == C ||
        Board[i-1][j+1] == C)
      return true;
  }
  return false;
}

static bool isUnderPawnAttack(char (&Board)[REAL_WIDTH][REAL_WIDTH], int i, int j) {
  return isUnderPawnAttack_1(Board, i, j, 'p') ||
         isUnderPawnAttack_1(Board, i, j, 'P');
}

static bool isUnderKingAttack(char (&Board)[REAL_WIDTH][REAL_WIDTH], int i, int j) {
  if (std::tolower(Board[i-1][j-1]) == 'k' ||
      std::tolower(Board[i-1][j]) == 'k' ||
      std::tolower(Board[i-1][j+1]) == 'k' ||
      std::tolower(Board[i][j-1]) == 'k' ||
      std::tolower(Board[i][j+1]) == 'k' ||
      std::tolower(Board[i+1][j-1]) == 'k' ||
      std::tolower(Board[i+1][j]) == 'k' ||
      std::tolower(Board[i+1][j+1]) == 'k')
    return true;
  return false;
}

static bool isUnderStraightLineAttack(char (&Board)[REAL_WIDTH][REAL_WIDTH], int NowI, int NowJ, char C) {
  for (int i = NowI, j = NowJ-1; j >= 2;  --j) {
    if (std::tolower(Board[i][j]) == C) return true;
    if (std::isalpha(Board[i][j]))  break;
  }
  for (int i = NowI, j = NowJ+1; j < 10;  ++j) {
    if (std::tolower(Board[i][j]) == C) return true;
    if (std::isalpha(Board[i][j]))  break;
  }
  for (int i = NowI-1, j = NowJ; i >= 2;  --i) {
    if (std::tolower(Board[i][j]) == C) return true;
    if (std::isalpha(Board[i][j]))  break;
  }
  for (int i = NowI+1, j = NowJ; j < 10;  ++i) {
    if (std::tolower(Board[i][j]) == C) return true;
    if (std::isalpha(Board[i][j]))  break;
  }
  return false;
}

static bool isUnderDiagonalLineAttack(char (&Board)[REAL_WIDTH][REAL_WIDTH], int NowI, int NowJ, char C) {
  for (int i = NowI-1, j = NowJ-1; i >= 2 && j >= 2;  --i, --j) {
    if (std::tolower(Board[i][j]) == C) return true;
    if (std::isalpha(Board[i][j]))  break;
  }
  for (int i = NowI-1, j = NowJ+1; i >= 2 && j < 10;  --i, ++j) {
    if (std::tolower(Board[i][j]) == C) return true;
    if (std::isalpha(Board[i][j]))  break;
  }
  for (int i = NowI+1, j = NowJ-1; i < 10 && j >= 2;  ++i, --j) {
    if (std::tolower(Board[i][j]) == C) return true;
    if (std::isalpha(Board[i][j]))  break;
  }
  for (int i = NowI+1, j = NowJ+1; i < 10 && j < 10; ++i, ++j) {
    if (std::tolower(Board[i][j]) == C) return true;
    if (std::isalpha(Board[i][j]))  break;
  }
  return false;
}

static bool isUnderRookAttack(char (&Board)[REAL_WIDTH][REAL_WIDTH], int i, int j) {
  return isUnderStraightLineAttack(Board, i, j, 'r');
}

static bool isUnderBishopAttack(char (&Board)[REAL_WIDTH][REAL_WIDTH], int i, int j) {
  return isUnderDiagonalLineAttack(Board, i, j, 'b');
}

static bool isUnderQueenAttack(char (&Board)[REAL_WIDTH][REAL_WIDTH], int i, int j) {
  return isUnderStraightLineAttack(Board, i, j, 'q') ||
         isUnderDiagonalLineAttack(Board, i, j, 'q');
}

static bool isUnderKnightAttack(char (&Board)[REAL_WIDTH][REAL_WIDTH], int i, int j) {
  if (std::tolower(Board[i-2][j-1]) == 'n' ||
      std::tolower(Board[i-2][j+1]) == 'n' ||
      std::tolower(Board[i-1][j-2]) == 'n' ||
      std::tolower(Board[i-1][j+2]) == 'n' ||
      std::tolower(Board[i+2][j-1]) == 'n' ||
      std::tolower(Board[i+2][j+1]) == 'n' ||
      std::tolower(Board[i+1][j-2]) == 'n' ||
      std::tolower(Board[i+1][j+2]) == 'n')
    return true;
  return false;
}

static bool isUnderAttack(char (&Board)[REAL_WIDTH][REAL_WIDTH], int i, int j) {
  if (isUnderPawnAttack(Board, i, j))
    return true;
  if (isUnderKingAttack(Board, i, j))
    return true;
  if (isUnderRookAttack(Board, i, j))
    return true;
  if (isUnderBishopAttack(Board, i, j))
    return true;
  if (isUnderQueenAttack(Board, i, j))
    return true;
  if (isUnderKnightAttack(Board, i, j))
    return true;
  return false;
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  std::string Input;
  while (std::getline(is, Input)) {

    char Board[REAL_WIDTH][REAL_WIDTH];
    std::fill (&Board[0][0], &Board[REAL_WIDTH-1][REAL_WIDTH-1]+1, 0);
    int i = 2, j = 2;
    for (auto C : Input) {
      if (C == '/') {
        if (j != BOARD_WIDTH + 2) {
          os << "0\n";
          break;
        }
        i++;  j = 2;
        if (i > BOARD_WIDTH + 1) {
          os << "0\n";
          break;
        }
      } else if (std::isdigit(C)) {
        int N = C - 48;
        while (N-- > 0) j++;
        if (j > BOARD_WIDTH + 2) {
          os << "0\n";
          break;
        }
      } else {
        UASSERT (std::isalpha(C));
        bool IsValid = true;
        switch (C) {
        default:
          IsValid = false;
          break;
        case 'r':
        case 'n':
        case 'b':
        case 'q':
        case 'k':
        case 'p':
        case 'R':
        case 'N':
        case 'B':
        case 'Q':
        case 'K':
        case 'P':
          break;
        }
        if (!IsValid) {
          os << "0\n";
          break;
        }
        Board[i][j++] = C;
      }
    }

#if 0
    REP (i, 2, BOARD_WIDTH + 2) {
      REP (j, 2, BOARD_WIDTH + 2) {
        auto C = Board[i][j];
        if (std::isalpha(C))  os << C;
        else  os << "?";
      }
      os << "\n";
    }
#endif

    int Total = 0;
    REP (i, 2, BOARD_WIDTH + 2) {
      REP (j, 2, BOARD_WIDTH + 2) {
        if (!std::isalpha(Board[i][j]) && !isUnderAttack(Board, i, j)) {
          Total++;
#if 0
          os << "No attack index: (" << i-2 << ", " << j-2 << ")\n";
#endif
        }
      }
    }

    os << Total << "\n";

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
