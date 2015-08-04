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
  std::set<char> Universal { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' };
  while (Count-- > 0) {
    std::set< std::pair<std::set<char>, std::set<char>> > Targets;
    std::set<char> WhiteList;
    REP (i, 0, 3) {
      std::string L, R, Status;
      is >> L >> R >> Status;
      if (Status == "down")  std::swap(L, R);
      DEBUG (os << "Read " << L << " " << R << ((Status == "even") ? " (even)" : " (up)") << "\n";);

      if (Status == "even") {
        ITERATOR_REP (i, e, L) WhiteList.insert(*i);
        ITERATOR_REP (i, e, R) WhiteList.insert(*i);
        continue;
      }

      std::set<char> LSuspicious;
      std::set<char> RSuspicious;
      ITERATOR_REP (i, e, L)
        if (WhiteList.find(*i) == WhiteList.end())  LSuspicious.insert(*i);
      ITERATOR_REP (i, e, R)
        if (WhiteList.find(*i) == WhiteList.end())  RSuspicious.insert(*i);
      Targets.insert(std::make_pair(LSuspicious, RSuspicious));
    }

    DEBUG (
      os << "\n";
      os << "Universal: ";
      ITERATOR_REP(i, e, Universal)  os << *i << " ";
      os << "\n";
      os << "WhiteList: ";
      ITERATOR_REP(i, e, WhiteList)  os << *i << " ";
      os << "\n";

      os << "Target pairs: \n";
      ITERATOR_REP (i, e, Targets) {
        auto &LSet = i->first;
        auto &RSet = i->second;
        ITERATOR_REP(ji, je, LSet)  os << *ji << " ";
        os << " ( heavier than ) ";
        ITERATOR_REP(ji, je, RSet)  os << *ji << " ";
        os << "\n";
      }
          );

    char Target = ' ';
    bool IsHeavy = false;
    bool Done = false;
    ITERATOR_REP (i, e, Targets) {
      auto &LSet = const_cast<std::set<char> &>(i->first);
      auto &RSet = const_cast<std::set<char> &>(i->second);
      bool IsSteady;
      do {
        IsSteady = true;
        ITERATOR_REP (i, e, LSet)
          if (WhiteList.find(*i) != WhiteList.end()) {
            LSet.erase(i);
            IsSteady = false;
            break;  // Iterator invalid
          }
        ITERATOR_REP (i, e, RSet)
          if (WhiteList.find(*i) != WhiteList.end()) {
            RSet.erase(i);
            IsSteady = false;
            break;  // Iterator invalid
          }
      } while (!IsSteady);

      if (LSet.empty() && RSet.size() == 1) {
        Target = *RSet.begin();
        IsHeavy = false;
        Done = true;
        break;
      }
      if (RSet.empty() && LSet.size() == 1) {
        Target = *LSet.begin();
        IsHeavy = true;
        Done = true;
        break;
      }
    }

    DEBUG(
      os << "### After one iteration ### \n";
      os << "Target pairs: \n";
      ITERATOR_REP (i, e, Targets) {
        auto &LSet = i->first;
        auto &RSet = i->second;
        ITERATOR_REP(ji, je, LSet)  os << *ji << " ";
        os << " ( heavier than ) ";
        ITERATOR_REP(ji, je, RSet)  os << *ji << " ";
        os << "\n";
      }
         );

    std::set<char> Suspicious;
    std::set_difference(ALL(Universal), ALL(WhiteList), std::inserter(Suspicious, Suspicious.end()));

    if (Suspicious.size() == 1) {
      Target = *Suspicious.begin();
      Done = true;
      IsHeavy = true;
    }

    DEBUG (
      os << "Suspicious: ";
      ITERATOR_REP(i, e, Suspicious)  os << *i << " ";
      os << "\n";
          );

    if (!Done) {
      UASSERT (Targets.size() > 1);
      std::set<char> LRemainingSet;
      std::set<char> RRemainingSet;
      ITERATOR_REP (i, e, Targets) {
        if (i == Targets.begin()) {
          ITERATOR_REP (j, je, i->first)  LRemainingSet.insert(*j);
          ITERATOR_REP (j, je, i->second)  RRemainingSet.insert(*j);
        } else {
          for (auto j = LRemainingSet.begin(); j != LRemainingSet.end(); ) {
            auto iter = j++;
            if (i->first.find(*iter) == i->first.end()) LRemainingSet.erase(iter);
          }
          for (auto j = RRemainingSet.begin(); j != RRemainingSet.end(); ) {
            auto iter = j++;
            if (i->second.find(*iter) == i->second.end()) RRemainingSet.erase(iter);
          }
        }
      }

      DEBUG (
        os << "L Remaining intersection: ";
        ITERATOR_REP(i, e, LRemainingSet)  os << *i << " ";
        os << "\n";
        os << "R Remaining intersection: ";
        ITERATOR_REP(i, e, RRemainingSet)  os << *i << " ";
        os << "\n";
            );

      if (LRemainingSet.empty() && RRemainingSet.size() == 1) {
        Target = *RRemainingSet.begin();
        IsHeavy = false;
        Done = true;
      }
      if (RRemainingSet.empty() && LRemainingSet.size() == 1) {
        Target = *LRemainingSet.begin();
        IsHeavy = true;
        Done = true;
      }
    }

    UASSERT (Done);
    UASSERT (Target != ' ');
    os << Target << " is the counterfeit coin and it is ";
    if (IsHeavy)  os << "heavy.\n";
    else  os << "light.\n";
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
