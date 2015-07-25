//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

// Define and implement your data structure here.
int People::TotalPeople = -1;

People::People() {
  mRemainingVoteList.reserve(TotalPeople/2);
}

People::~People() {
}

void People::createNewRemainingVoteList() {
  mRemainingVoteList.push_back(std::vector<int>());
  mRemainingVoteList.rbegin()->reserve(20);
}

void People::appendRemainingVote(int Index) {
  mRemainingVoteList.rbegin()->push_back(Index);
}

bool People::WinThanObj::operator()(const People &A, const People &B) const {
  if (A.isRetired())
    return false;
  if (B.isRetired())
    return true;
  return A.getVoteCount() > B.getVoteCount();
}
