//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//
#ifndef UVA_H
#define UVA_H

// Include all headers in here since UVa can only submit one merged file.
// This is not a good behavior but it works.

// C++
#include <iomanip>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
// C
#include <cassert>
#include <cstring>

#ifndef UASSERT
#ifndef ONLINE_JUDGE
#define UASSERT(expr) assert (expr)
#else
#define UASSERT(expr)
#endif
#endif

#ifndef DEBUG
#ifndef ONLINE_JUDGE
#define DEBUG(expr) do { expr; } while (0)
#else
#define DEBUG(expr)
#endif
#endif

// Define your data structure here.
class People {
  int mIndex = 0;
  std::string mName;
  bool mRetired = false;
  std::vector <std::vector<int>> mRemainingVoteList;

public:
  People();
  ~People();

public:
  void createNewRemainingVoteList();
  void appendRemainingVote(int Index);
  void setRetired() {
    mRetired = true;
  }
  bool isRetired() const { return mRetired; }
  void setName(const std::string &s) {
    mName = s;
  }
  std::string getName() const { return mName; }
  void setIndex(int i) {
    mIndex = i;
  }
  int getIndex() const { return mIndex; }
  int getVoteCount() const { return mRemainingVoteList.size(); }
  std::vector<std::vector<int>> &getRemainingVoteList() {
    return mRemainingVoteList;
  }

  struct WinThanObj {
    bool operator()(const People &, const People &) const;
  };

public:
  static int TotalPeople;
};

#endif // UVA_H
