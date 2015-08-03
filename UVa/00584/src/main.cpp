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
  // TODO
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
        UASSERT (CurRoll % 2 || CurRoll == 20);
        Roll[CurRoll++] = 20;
      } else if (std::toupper(In) == 'X') {
        UASSERT (CurRoll % 2 == 0 || CurRoll > 18);
        Roll[CurRoll++] = 21;
        Roll[CurRoll++] = -1;
      }
    }

#if 1
    os << "Roll: ";
    for (int i = 0; i < 24; i += 2) {
      os << Roll[i] << " " << Roll[i+1] << "\t";
    }
    os << "\n";
#endif

    REP (i, 0, 10) {
      int FrameIdx = i * 2;
      int NextFrameIdx = (i+1) * 2;
      int NextNextFrameIdx = (i+2) * 2;
      if (Roll[FrameIdx] == 21) {
        // Strike
        int NextScore = getRollScore(NextFrameIdx);
        int NextNextScore = getRollScore(NextFrameIdx+1);
        if (NextScore == 10)
          NextNextScore = getRollScore(NextNextFrameIdx);
        FrameScore[i] = 10 + NextScore + NextNextScore;
      } else {
        UASSERT (Roll[FrameIdx] != -1 && Roll[FrameIdx] != 20);
        if (Roll[FrameIdx+1] == 20)
          FrameScore[i] = 10 + getRollScore(NextFrameIdx);
        else
          FrameScore[i] = getRollScore(FrameIdx) + getRollScore(FrameIdx+1);
      }
    }

#if 1
    os << "Score: ";
    for (int i = 0; i < 10; ++i) {
      os << i+1 << ": " << FrameScore[i] << "\t";
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
