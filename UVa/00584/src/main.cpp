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
  std::string Input;
  while (std::getline(is, Input), Input != "Game Over") {
    int Roll[12*2] = {};  // 0, 1, 2, ..., 9, 10
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
        Roll[CurRoll] = 10 - Roll[CurRoll-1];
        CurRoll++;
      } else if (std::toupper(In) == 'X') {
        UASSERT (CurRoll % 2 == 0);
        Roll[CurRoll++] = 10;
        Roll[CurRoll++] = 0;
      }
    }

#ifndef ONLINE_JUDGE
    os << "Roll: ";
    for (int i = 0; i < 24; i += 2) {
      if (Roll[i] == 10 && i % 2 == 0)  os << "X .\t";
      else if (Roll[i+1] + Roll[i] == 10) os << Roll[i] << " /\t";
      else  os << Roll[i] << " " << Roll[i+1] << "\t";
    }
    os << "\n";
#endif

    REP (i, 0, 10) {
      int FrameIdx = i * 2;
      FrameScore[i] = Roll[FrameIdx] + Roll[FrameIdx+1];
    }

    REP (i, 0, 10) {
      int FrameIdx = i * 2;
      int NextFrameIdx = (i+1) * 2;
      int NextNextFrameIdx = (i+2) * 2;
      if (Roll[FrameIdx] == 10) { // 'X'
        if (Roll[NextFrameIdx] == 10) { // 'X' 'X' ?
          FrameScore[i] += 10 + Roll[NextNextFrameIdx];
        } else {
          FrameScore[i] += Roll[NextFrameIdx] + Roll[NextFrameIdx+1];
        }
      } else if (Roll[FrameIdx] + Roll[FrameIdx+1] == 10) { // '/'
        FrameScore[i] += Roll[NextFrameIdx];
      }
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
