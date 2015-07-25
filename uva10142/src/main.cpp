//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

int pickWinVoteIndex(std::vector<People> &Men) {
  std::multiset<People, People::WinThanObj> SortedMen {Men.begin(), Men.end() };
#ifndef ONLINE_JUDGE
  std::cerr << "Sorted Men: \n";
  for (auto &SM : SortedMen) {
    std::cerr << "Index, Vote, Retired: " << SM.getIndex() << ", " << SM.getVoteCount() << ", " << SM.isRetired() << "\n";
  }
  std::cerr << "\n";
#endif
  return SortedMen.begin()->getIndex();
}

bool checkAllTied(std::vector<People> &Men) {
  int NVote = -1;
  for (auto &M : Men) {
    if (M.isRetired())
      continue;

    if (NVote < 0) {
      NVote = M.getVoteCount();
      continue;
    }

    if (M.getVoteCount() != NVote)
      return false;
  }
  return true;
}

void retireLastAndVoteAgain(std::vector<People> &Men) {
  std::multiset<People, People::WinThanObj> SortedMen { Men.begin(), Men.end() };
#ifndef ONLINE_JUDGE
  std::cerr << "Sorted Men: \n";
  for (auto &SM : SortedMen) {
    std::cerr << "Index, Vote, Retired: " << SM.getIndex() << ", " << SM.getVoteCount() << ", " << SM.isRetired() << "\n";
  }
  std::cerr << "\n";
#endif

  std::vector<int> ToBeRetiredIndexes;
  int MinVoteCount = -1;
  for (auto i = SortedMen.rbegin(), e = SortedMen.rend(); i != e; ++i) {
    if (i->isRetired())
      continue;

    if (MinVoteCount == -1)
      MinVoteCount = i->getVoteCount();

    if (MinVoteCount != i->getVoteCount())
      break;

    Men[i->getIndex()].setRetired();
    ToBeRetiredIndexes.push_back(i->getIndex());
  }

  for (auto i : ToBeRetiredIndexes) {
    auto &M = Men[i];
    auto &List = M.getRemainingVoteList();
    for (auto &L : List) {
      if (L.size() == 0)
        continue;
      int NewID = -1, j = 0;
      for ( ; (size_t)j < L.size(); ) {
        NewID = L[j++];
        if (!Men[NewID].isRetired())
          break;
      }
      if ((size_t)j != L.size())
        Men[NewID].createNewRemainingVoteList();
#ifndef ONLINE_JUDGE
      std::cerr << "Add to Men[" << NewID << "], New Vote#: " << Men[NewID].getVoteCount() << "\n";
#endif
      for ( ; (size_t)j < L.size(); ++j) {
        Men[NewID].appendRemainingVote(L[j]);
      }
    }
    List.clear();
    UASSERT (M.getVoteCount() == 0);
  }

#ifndef ONLINE_JUDGE
  std::cerr << "Unsorted Men after retirement: \n";
  for (auto &M : Men) {
    std::cerr << "Index, Vote, Retired: " << M.getIndex() << ", " << M.getVoteCount() << ", " << M.isRetired() << "\n";
  }
  std::cerr << "\n";
#endif
}

void startEach(std::istream &is, std::ostream &os) {
  int NPeople;
  is >> NPeople;
  std::string Input;
  std::getline(is, Input);

  std::vector <People> Men;
  Men.reserve(NPeople);
  for (int i = 0; i < NPeople; ++i) {
    People Man;
    std::getline(is, Input);
    Man.setIndex(i);
    Man.setName(Input);
    Men.push_back(Man);
  }

  int VoteCount = 0;
  while (true) {
    std::getline(is, Input);
    if (Input.empty())
      break;

    std::stringstream ss;
    ss << Input;
    VoteCount += 1;
    int ManID;
    ss >> ManID;
    Men[ManID-1].createNewRemainingVoteList();
    for (int i = 1; i < NPeople; ++i) {
      int Vote;
      ss >> Vote;
      Men[ManID-1].appendRemainingVote(Vote-1);
    }
  }

  while (true) {
    int Win = pickWinVoteIndex(Men);
    if (Win >= 0 &&
        Men[Win].getVoteCount() > VoteCount / 2) {
      os << Men[Win].getName() << std::endl;
      break;
    }

    bool Tied = checkAllTied(Men);
    if (Tied) {
      for (auto &M : Men) {
        if (!M.isRetired())
          os << M.getName() << std::endl;
      }
      break;
    }

    retireLastAndVoteAgain(Men);
  }
}

int runUVa(std::istream &is, std::ostream &os) {
  // Implement here.
  int NCases;
  is >> NCases;
  std::string Input;
  std::getline(is, Input);
  std::getline(is, Input);
  for (int i = 0; i < NCases; ++i) {
#ifndef ONLINE_JUDGE
    std::cerr << "Case #" << i << "\n";
#endif
     startEach(is, os);
     if (i != NCases - 1)
       os << std::endl;
  }
  return 0;
}

int main(int argc, char **argv) {
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
