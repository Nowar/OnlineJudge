//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

int Roll[12*2] = {};  // 0, 1, 2, ..., 9, / => 20, X => 21, -1 means skip

static int getRollScore(int RollIdx) {
  int Score = Roll[RollIdx];
  if (Score < 10) return Score;

  if (Score == 21) {
    UASSERT (RollIdx % 2 == 0);
    UASSERT (Roll[RollIdx+1] == -1);
    int NextScore = Roll[RollIdx+2];
    if (NextScore == 21)  NextScore = 10;
    UASSERT (NextScore <= 10 && NextScore >= 0);

    int NextNextScore = Roll[RollIdx+3];
    if (Roll[RollIdx+2] == 21)  NextNextScore = Roll[RollIdx+4];
    if (NextNextScore == 21)  NextNextScore = 10;
    if (NextNextScore == 20) {
      return 10 + 10 - Roll[RollIdx+1];
    } else {
      UASSERT (NextNextScore <= 10 && NextNextScore >= 0);
      return 10 + NextScore + NextNextScore - Roll[RollIdx+1];
    }
  }

  if (Score == 20) {
    UASSERT (RollIdx % 2);
    int NextScore = Roll[RollIdx+1];
    if (NextScore == 21)  NextScore = 10;
    UASSERT (NextScore <= 10 && NextScore >= 0);
    return 10 + NextScore - Roll[RollIdx-1];
  }
  return 0;
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  std::string Input;
  while (std::getline(is, Input), Input != "Game Over") {
    std::fill(Roll, Roll+24, 0);
    int FrameScore[10] = {};
    std::stringstream ss;
    ss << Input;
    char In;
    int CurRoll = 0;
    while (ss >> In) {
      if (std::isdigit(In)) {
        Roll[CurRoll++] = In - '0';
      } else if (In == '/') {
        UASSERT (CurRoll % 2);
        Roll[CurRoll++] = 20;
      } else if (std::toupper(In) == 'X') {
        UASSERT (CurRoll % 2 == 0);
        Roll[CurRoll++] = 21;
        Roll[CurRoll++] = -1;
      }
    }

#ifndef ONLINE_JUDGE
    os << "Roll: ";
    for (int i = 0; i < 24; i += 2) {
      if (Roll[i] == 21)  os << "X .\t";
      else if (Roll[i+1] == 20) os << Roll[i] << " /\t";
      else  os << Roll[i] << " " << Roll[i+1] << "\t";
    }
    os << "\n";
#endif

    REP (i, 0, 10) {
      int FrameIdx = i * 2;
      FrameScore[i] = getRollScore(FrameIdx) + getRollScore(FrameIdx+1);
    }

#ifndef ONLINE_JUDGE
    os << "Score: ";
    for (int i = 0; i < 10; ++i) {
      os << FrameScore[i] << "\t";
    }
    os << "\n";
#endif

    int Sum = 0;
    REP (i, 0, 10)  Sum += FrameScore[i];
    os << Sum << "\n";
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
