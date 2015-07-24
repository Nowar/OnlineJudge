#include "NQueen.h"

void NQueen::resetSum(unsigned Sum) {
  TotalSum = Sum;
}

void NQueen::resetDim(unsigned Dim) {
  MaxDim = Dim;
  SolutionNumber = 0;
  MinSurface = -1;
}

void NQueen::dump() {
  assert (AnswerSet.size() == MaxDim);
  for (auto Answer : AnswerSet) {
    std::cerr << "(" << Answer.first << ", " << Answer.second << ") ";
  }
  std::cerr << " Surface: " << calculateSurface() << std::endl;
}

unsigned NQueen::calculateSurface() {
  unsigned TotalSurface = 0;
  for (auto Answer : AnswerSet) {
    unsigned R = Answer.first;
    unsigned H = Answer.second;
    TotalSurface += 2 * R * H; 
  }
  unsigned R = AnswerSet[AnswerSet.size() - 1].first;
  TotalSurface += R * R;

  return TotalSurface;
}

bool NQueen::solveEach(unsigned MinR, unsigned MinH, unsigned MaxSum, unsigned Iteration) {
  if (Iteration == MaxDim) {
    if (MaxSum == 0) {
#ifndef ONLINE_JUDGE
      dump();
#endif
      unsigned TotalSurface = calculateSurface();
      if (TotalSurface < MinSurface)
        MinSurface = TotalSurface;
      SolutionNumber += 1;
      return true;
    } else {
      return false;
    }
  }

  for (unsigned i = MinR + 1; i < MaxSum; ++i) {
    for (unsigned j = MinH + 1; j < MaxSum; ++j) {
      unsigned result = i * i * j;
      if (result <= MaxSum) {
        AnswerSet.push_back(std::make_pair(i, j));
        solveEach(i, j, MaxSum - result, Iteration + 1);
        AnswerSet.resize(AnswerSet.size() - 1);
      } else {
        break;  // Over
      }
    }
  }
  return false;
}

void NQueen::solve() {
  solveEach(0, 0, 100, 0);
}

unsigned NQueen::getSolutionNumber() {
  return SolutionNumber;
}

unsigned NQueen::getMinSurface() {
  return MinSurface;
}
