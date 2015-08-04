//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static bool checkDone(bool (&Checked)[5][5], int i, int j) {
  if (Checked[i][0] && Checked[i][1] && Checked[i][2] && Checked[i][3] && Checked[i][4])
    return true;
  if (Checked[0][j] && Checked[1][j] && Checked[2][j] && Checked[3][j] && Checked[4][j])
    return true;
  if (i == j) {
    if (Checked[0][0] && Checked[1][1] && Checked[3][3] && Checked[4][4])
      return true;
  }
  if (i == 5-1-j) {
    if (Checked[0][4] && Checked[1][3] && Checked[3][1] && Checked[4][0])
      return true;
  }
  return false;
}

static void runUVa_1(std::istream &is, std::ostream &os) {
  bool Checked[5][5] = {};
  Checked[2][2] = true;
  std::map<int, std::pair<int, int>> Index;
  REP (i, 1, 6) {
    REP (j, 1, 6) {
      if (i == 3 && j == 3) continue;
      int Card;
      is >> Card;
      Index[Card] = std::make_pair(i, j);
    }
  }

  int N = 0;
  int Card;
  while (true) {
    N++;
    is >> Card;
    DEBUG (os << "Got card: " << Card << "\n";);
    auto Pair = Index[Card];
    if (Pair.first == 0)
      continue;
    int i = Pair.first;
    int j = Pair.second;
    DEBUG (os << "(i, j): " << i << ", " << j << "\n";);
    Checked[i-1][j-1] = true;

    if (checkDone(Checked, i-1, j-1))
      break;
    DEBUG (REP (i, 0, 5) { REP (j, 0, 5) { os << Checked[i][j] << " "; } os << "\n"; } os << "\n";);
  }
  os << "BINGO after " << N << " numbers announced\n";
  while (N++ != 75) is >> Card;
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  int Count;
  is >> Count;
  while (Count-- > 0)
    runUVa_1(is, os);
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
