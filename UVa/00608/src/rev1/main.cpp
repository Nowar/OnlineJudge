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
  int Count;
  is >> Count;
  while (Count-- > 0) {
    std::set<char> Universal { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' };
    std::set<char> Suspicious(Universal);
    std::set<char> WhiteList;
    bool isLight;
    std::string L[3], R[3], Status[3];
    REP (i, 0, 3) {
      is >> L[i] >> R[i] >> Status[i];
      DEBUG (os << "Read " << L[i] << " " << R[i] << " " << Status[i] << "\n";);
    }

    int Idx = 0;
    bool Found = false;
    std::set<char> AllSect[3];
    while (Suspicious.size() != 1 && !Found) {
      if (Status[Idx] == "even") {
        ITERATOR_REP (i, e, L[Idx]) {
          auto C = *i;
          Suspicious.erase(C);
          WhiteList.insert(C);
        }
        ITERATOR_REP (i, e, R[Idx]) {
          auto C = *i;
          Suspicious.erase(C);
          WhiteList.insert(C);
        }
        ITERATOR_REP (i, e, Suspicious) AllSect[Idx].insert(*i);
      } else {
        std::set<char> NewL, NewR;
        std::set_difference(ALL(L[Idx]), ALL(WhiteList), std::inserter(NewL, NewL.end()));
        std::set_difference(ALL(R[Idx]), ALL(WhiteList), std::inserter(NewR, NewR.end()));
        if (NewL.empty() && NewR.size() == 1) {
          isLight = (Status[Idx] == "up") ? true : false;
          Found = true;
        } else if (NewL.size() == 1 && NewR.empty()) {
          isLight = (Status[Idx] == "up") ? false : true;
          Found = true;
        }
        ITERATOR_REP (i, e, NewL) AllSect[Idx].insert(*i);
        ITERATOR_REP (i, e, NewR) AllSect[Idx].insert(*i);
      }
      DEBUG (
        os << "Visiting Idx: " << Idx << "\n";
        os << "Suspicious: ";
        ITERATOR_REP(i, e, Suspicious)  os << *i << " ";
        os << "\n";
        os << "WhiteList: ";
        ITERATOR_REP(i, e, WhiteList)  os << *i << " ";
        os << "\n";
            );

      if (Found)
        break;

      if (Idx == 2) { // Check special case whenever each loop final iteration
        DEBUG (
          os << "All sect [0]: ";
          ITERATOR_REP(i, e, AllSect[0])  os << *i << " ";
          os << "\n";
          os << "All sect [1]: ";
          ITERATOR_REP(i, e, AllSect[1])  os << *i << " ";
          os << "\n";
          os << "All sect [2]: ";
          ITERATOR_REP(i, e, AllSect[2])  os << *i << " ";
          os << "\n";
              );
        std::set<char> InterSect[3];
        std::set_intersection(ALL(AllSect[0]), ALL(AllSect[1]), std::inserter(InterSect[0], InterSect[0].end()));
        std::set_intersection(ALL(AllSect[0]), ALL(AllSect[2]), std::inserter(InterSect[1], InterSect[1].end()));
        std::set_intersection(ALL(InterSect[0]), ALL(InterSect[1]), std::inserter(InterSect[2], InterSect[2].end()));
        AllSect[0].clear(); AllSect[1].clear(); AllSect[2].clear();
        DEBUG (
          os << "Intersect: ";
          ITERATOR_REP(i, e, InterSect[2])  os << *i << " ";
          os << "\n";
              );

        UASSERT (InterSect[2].size() == 1);
        if (InterSect[2].size() == 1) {
          auto C = *InterSect[2].begin();
          Suspicious.clear();
          Suspicious.insert(C);
          Found = true;
          if (L[0].find(C) != std::string::npos && Status[0] != "even") { isLight = (Status[0] == "up") ? false : true; break;  }
          if (R[0].find(C) != std::string::npos && Status[0] != "even") { isLight = (Status[0] == "up") ? true : false; break;  }
          if (L[1].find(C) != std::string::npos && Status[1] != "even") { isLight = (Status[1] == "up") ? false : true; break;  }
          if (R[1].find(C) != std::string::npos && Status[1] != "even") { isLight = (Status[1] == "up") ? true : false; break;  }
          if (L[2].find(C) != std::string::npos && Status[2] != "even") { isLight = (Status[2] == "up") ? false : true; break;  }
          if (R[2].find(C) != std::string::npos && Status[2] != "even") { isLight = (Status[2] == "up") ? true : false; break;  }
        }
      }

      Idx = (Idx+1) % 3;
    }

    UASSERT (Suspicious.size() == 1);
    os << *Suspicious.begin() << " is the counterfeit coin and it is ";
    if (isLight)  os << "light.\n";
    else  os << "heavy.\n";
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
