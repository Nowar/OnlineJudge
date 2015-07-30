//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static const int kMaxRow = 1000;

static void startEach(std::istream &is, std::ostream &os) noexcept {
  int NPeople;
  is >> NPeople;
  std::string Input;
  std::getline(is, Input);

  UASSERT (NPeople <= 20);
  int Table[kMaxRow][NPeople];
  std::string Name[20];
  for (int i = 0; i < NPeople; ++i) {
    std::getline(is, Input);
    Name[i] = Input;
  }

  int VoteWinCount[NPeople]; // Count each man has how many votes
  void *VoteTablePos[NPeople][kMaxRow];  // Cache the Table position it got vote
  int Retired[NPeople]; // 0: not retired, 1: retiring, 2: retired
  int VoteCountIndex[NPeople]; // Cache the index of each man

  std::fill(&VoteWinCount[0], &VoteWinCount[NPeople], 0);
  std::fill(&VoteCountIndex[0], &VoteCountIndex[NPeople], 0);
  std::fill(Retired, Retired+NPeople, 0);

  int TotalVoteCount = 0;
  while (true) {
    std::getline(is, Input);
    DEBUG (std::cerr << "Read input line: " << Input << "\n");
    if (Input.empty())
      break;

    std::stringstream ss;
    ss << Input;
    for (int i = 0; i < NPeople; ++i) {
      int Vote;
      ss >> Vote;
      Vote -= 1;  // Computer index <-> Human index
      UASSERT (Vote >= 0 && Vote < NPeople);
      Table[TotalVoteCount][i] = Vote;
      int PosIndex = VoteCountIndex[Vote]++;
      VoteTablePos[Vote][PosIndex] = &Table[TotalVoteCount][i];
      if (i == 0)
        VoteWinCount[Vote] += 1;
    }
    TotalVoteCount += 1;
  }

  DEBUG (
    for (int i = 0; i < NPeople; ++i) {
      std::cerr << "Dump each man got votes: Man[" << i+1 << "] : " << VoteWinCount[i] << ", Retired: " << Retired[i] << "\n";
    }
  );

  UASSERT (TotalVoteCount <= kMaxRow);

  // Find answer now...
  while (true) {
    int MaxVoteCount = 0;
    int MinVoteCount = 0x7fffffff;
    int MaxPeopleIndex = 0;
    for (int i = 0; i < NPeople; ++i) {
      if (Retired[i])
        continue;

      if (VoteWinCount[i] > MaxVoteCount) {
        MaxVoteCount = VoteWinCount[i];
        MaxPeopleIndex = i;
      }
      if (VoteWinCount[i] < MinVoteCount)
        MinVoteCount = VoteWinCount[i];

      UASSERT (MaxVoteCount >= 0);
      UASSERT (MinVoteCount < 0x7fffffff);
    }
    DEBUG (std::cerr << "MaxPeopleIndex: " << MaxPeopleIndex+1 << "\n");
    DEBUG (std::cerr << "MaxCount: " << MaxVoteCount << "\n");
    DEBUG (std::cerr << "MinCount: " << MinVoteCount << "\n");
    if (MaxVoteCount > TotalVoteCount / 2) {
      os << Name[MaxPeopleIndex] << "\n";
      break;
    }
    if (MaxVoteCount == MinVoteCount) {
      for (int i = 0; i < NPeople; ++i) {
        if (Retired[i]) continue;
        os << Name[i] << "\n";
      }
      break;
    }

    // Retire some people.
    for (int i = 0; i < NPeople; ++i) {
      if (VoteWinCount[i] == MinVoteCount) {
        DEBUG (std::cerr << "Retire Man[" << i+1 << "]\n");
        Retired[i] = 1;
      }
    }

    for (int i = 0; i < NPeople; ++i) {
      if (Retired[i] != 1)
        continue;

      Retired[i] = 2;
      for (int j = 0; j < TotalVoteCount; ++j) {
        int *Entry = (int *) VoteTablePos[i][j];
        *Entry = -1;
      }
    }

    DEBUG (
      std::cerr << "Current table:\n";
      bool Infinite = true;
      for (int i = 0; i < TotalVoteCount; ++i) {
        for (int j = 0; j < NPeople; ++j) {
          if (Table[i][j] == -1)  std::cerr << "X ";
          else  std::cerr << Table[i][j]+1 << " ";

          if (Table[i][j] != -1)  Infinite = false;
        }
        std::cerr << "\n";
      }
      std::cerr << "\n";
      UASSERT (!Infinite && "Run into infinite loop.");
    );

    // Cleanup table and recompute
    std::fill(&VoteWinCount[0], &VoteWinCount[NPeople], 0);

    for (int i = 0; i < TotalVoteCount; ++i) {
      for (int j = 0; j < NPeople; ++j) {
        if (Table[i][j] != -1) {
          VoteWinCount[ Table[i][j] ] += 1;
          break;
        }
      }
    }
    DEBUG (
      for (int i = 0; i < NPeople; ++i) {
        std::cerr << "Dump each man got votes: Man[" << i+1 << "] : " << VoteWinCount[i] << ", Retired: " << Retired[i] << "\n";
      }
      std::cerr << "\n";
    );
  }
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  int NCases;
  is >> NCases;
  std::string Input;
  std::getline(is, Input);
  std::getline(is, Input);
  for (int i = 0; i < NCases; ++i) {
    DEBUG (std::cerr << "Case #" << i << "\n");
    startEach(is, os);
    if (i != NCases - 1)
      os << std::endl;
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
