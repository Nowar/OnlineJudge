//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

#define NUM_ROW   52
#define NUM_COL   1000000
int Refs[NUM_ROW][NUM_COL];

static int getRowIdx(char C) {
  UASSERT (std::isalpha(C));
  if (C > 'Z')
    C -= 'a' - 'Z' - 1;
  return C - 'A';
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  std::string Ref;
  std::getline(is, Ref);

  std::fill(&Refs[0][0], &Refs[NUM_ROW-1][NUM_COL-1]+1, NUM_COL);
  int CurRow[NUM_ROW] = {};
  REP (i, 0, Ref.size()) {
    char C = Ref[i];
    int RowIdx = getRowIdx(C);
    int ColIdx = CurRow[RowIdx]++;
    Refs[RowIdx][ColIdx] = i;
  }

  int N;
  is >> N;
  std::string Input;
  std::getline(is, Input);
  while (N-- > 0) {
    std::getline(is, Input);

    size_t InputI = 0;
    size_t FirstI = (size_t) -1;
    size_t LastI = 0;
    bool Succeed = true;
    for ( ; InputI != Input.size(); ++InputI) {
      auto C = Input[InputI];
      auto Idx = getRowIdx(C);
      auto RetIdx = std::lower_bound(&Refs[Idx][0], &Refs[Idx][NUM_COL-1]+1, LastI);
      if (RetIdx == &Refs[Idx][NUM_COL-1]+1 ||
          *RetIdx == NUM_COL) {
        Succeed = false;
        break;
      }
      LastI = *RetIdx + 1;
      if (FirstI == (size_t) -1)
        FirstI = LastI;
    }

    if (!Succeed)
      os << "Not matched\n";
    else
      os << "Matched " << FirstI-1 << " " << LastI-1 << "\n";
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
