//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

class UnionFindSet {
  vi Rank;
  vi Parent;

public:
  void resetSize(int i);
  bool isConnected(int i, int j) const;
  void unite(int i, int j);
  void dump() const;

private:
  int findParent(int i) const;
};

void UnionFindSet::resetSize(int i) {
  Rank.clear(); Parent.clear();
  Rank.reserve(i);  Parent.reserve(i);
  REP (j, 0, i) {
    Rank.push_back(j);
    Parent.push_back(j);
  }
}

bool UnionFindSet::isConnected(int i, int j) const {
  return findParent(i) == findParent(j);
}

int UnionFindSet::findParent(int i) const {
  return (Parent[i] == i) ? i : findParent(Parent[i]);
}

void UnionFindSet::unite(int i, int j) {
  int TopI = findParent(i);
  int TopJ = findParent(j);
  if (TopI == TopJ) return;

  if (Rank[TopI] < Rank[TopJ]) {
    Parent[TopI] = TopJ;
  } else if (Rank[TopI] > Rank[TopJ]) {
    Parent[TopJ] = TopI;
  } else {
    Parent[TopI] = TopJ;
    Rank[TopJ]++;
  }
}

void UnionFindSet::dump() const {
  DEBUG(
    REP (i, 0, Rank.size()) {
      std::cerr << "Node #" << i+1 << "\n";
      std::cerr << "  Parent = #" << Parent[i]+1 << "\n";
      std::cerr << "  Rank = #" << Rank[i]+1 << "\n";
    }
       );
}

static void runUVa_2(std::istream &is, std::ostream &os) {
  std::string Input;
  int Num;
  is >> Num;
  UnionFindSet UFS;
  UFS.resetSize(Num);
  std::getline(is, Input);
  int Yes = 0;
  int No = 0;
  while (std::getline(is, Input), !Input.empty()) {
    char C; int i, j;
    std::stringstream ss;
    ss << Input;
    ss >> C >> i >> j;

    UASSERT (C == 'c' || C == 'q');
    UASSERT (i > 0 && j > 0 && i<= Num && j <= Num);
    if (C == 'c') {
      UFS.unite(i-1, j-1);
      continue;
    }

    if (UFS.isConnected(i-1, j-1))
      Yes++;
    else
      No++;
  }
  os << Yes << "," << No << "\n";
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  int Count;
  std::string Input;
  is >> Count;
  std::getline(is, Input);
  std::getline(is, Input);
  while (Count-- > 0) {
    runUVa_2(is, os);
    if (Count != 0)
      os << "\n";
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
