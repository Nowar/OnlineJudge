#ifndef NQUEEN_H
#define NQUEEN_H

// Bad habbit, but can be easy for UVa.
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>

class NQueen {
public:
  void resetSum(unsigned Sum);
  void resetDim(unsigned Dim);
  void solve();
  unsigned getSolutionNumber();
  unsigned getMinSurface();

  typedef std::pair<unsigned, unsigned> AnswerTy;

private:
  unsigned TotalSum;
  unsigned MaxDim;
  unsigned SolutionNumber;
  unsigned MinSurface;
  std::vector<AnswerTy> AnswerSet;

private:
  bool solveEach(unsigned, unsigned, unsigned, unsigned);
  unsigned calculateSurface();
  void dump();
};

#endif
