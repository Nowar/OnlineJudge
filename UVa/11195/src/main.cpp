//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

int N;
bool Broken[15][15];
std::bitset<15> BSCol;
std::bitset<15*2-1> BSLUDiag;
std::bitset<15*2-1> BSRUDiag;
int Total = 0;

static void recurRow(int Row) {
  if (Row == N) {
    Total++;
    return;
  }
  REP (Col, 0, N) {
    if (!Broken[Row][Col] &&
        !BSCol[Col] &&
        !BSLUDiag[Row+Col] &&
        !BSRUDiag[Row-Col+(N-1)]) {
      BSCol[Col] = BSLUDiag[Row+Col] = BSRUDiag[Row-Col+(N-1)] = true;
      recurRow(Row+1);
      BSCol[Col] = BSLUDiag[Row+Col] = BSRUDiag[Row-Col+(N-1)] = false;
    }
  }
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  char C;
  int Id = 0;
  while (is >> N, N != 0) {
    std::fill(&Broken[0][0], &Broken[N-1][N-1]+1, false);
    BSCol.reset();
    BSLUDiag.reset();
    BSRUDiag.reset();
    Total = 0;

    REP (i, 0, N)
      REP (j, 0, N)
        if (is >> C, C == '*')
         Broken[i][j] = true;

    recurRow(0);
    os << "Case " << ++Id << ": " << Total << "\n";
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
