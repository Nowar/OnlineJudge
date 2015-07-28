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
  int Round;
  while (is >> Round) {
    if (Round == -1) break;

    os << "Round " << Round << "\n";
    std::string Q, A;
    std::getline(is, Q);
    std::getline(is, Q);
    std::getline(is, A);

    std::set<char> QSet { Q.begin(), Q.end() };
    std::set<char> ASet;  // Repeat input do not count twice.
    int Trial = 0;
    int CorrectCount = 0;
    for (auto c : A) {
      auto ret = ASet.insert(c);
      if (!ret.second)
        continue; // Redundant trial

      auto iter = QSet.find(c);
      if (iter == QSet.end()) {
        if (++Trial == 7)
          break;  // Failed, need no more trial
      } else {
        if (++CorrectCount == QSet.size())
          break;  // Succeed, need no more trial
      }
    }

    if (CorrectCount == QSet.size())
      os << "You win.\n";
    else if (Trial >= 7)
      os << "You lose.\n";
    else
      os << "You chickened out.\n";
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
