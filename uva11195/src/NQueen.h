#ifndef NQUEEN_H
#define NQUEEN_H

// Bad habbit, but can be easy for UVa.
#include <iostream>
#include <string>

class NQueen {
public:
  void resetDim(unsigned Dim);
  void setBroken(unsigned i, unsigned j);
  void solve();
  unsigned getSolutionNumber();

private:
  bool RealTable[15][15];
  bool BrokenTable[15][15];
  bool Column[15];      // For recursive fast lookup
  unsigned MaxDim;
  unsigned SolutionNumber;

private:
  void dump();
  bool solveRow(unsigned Row);
  bool checkDiagonal(unsigned Row, unsigned Col);
};

#endif
