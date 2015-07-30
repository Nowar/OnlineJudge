#include "NQueen.h"

void NQueen::resetDim(unsigned Dim) {
  MaxDim = Dim;
  SolutionNumber = 0;

  for (unsigned i = 0; i < Dim; ++i) {
    for (unsigned j = 0; j < Dim; ++j) {
      RealTable[i][j] = false;
      BrokenTable[i][j] = false;
    }
    Column[i] = false;
  }
}

void NQueen::setBroken(unsigned i, unsigned j) {
  BrokenTable[i][j] = true;
}

void NQueen::dump() {
  for (unsigned i = 0; i < MaxDim; ++i) {
    for (unsigned j = 0; j < MaxDim; ++j) {
      if (RealTable[i][j] == true)
        std::cerr <<  1;
      else
        std::cerr << 0;
    }
    std::cerr << std::endl;
  }
  std::cerr << std::endl;
}

bool NQueen::checkDiagonal(unsigned Row, unsigned Col) {
  // Row-1. Col+1
  unsigned i = Row, j = Col;
  while (i != 0 && j != MaxDim-1) {
    i -= 1;
    j += 1;
    if (RealTable[i][j])
      return false;
  }
  // Row-1. Col-1
  i = Row, j = Col;
  while (i != 0 && j != 0) {
    i -= 1;
    j -= 1;
    if (RealTable[i][j])
      return false;
  }
#if 0
  // Row+1. Col+1
  i = Row, j = Col;
  while (i != MaxDim-1 && j != MaxDim-1) {
    i += 1;
    j += 1;
    if (RealTable[i][j])
      return false;
  }
  // Row+1. Col-1
  i = Row, j = Col;
  while (i != MaxDim-1 && j != 0) {
    i += 1;
    j -= 1;
    if (RealTable[i][j])
      return false;
  }
#endif
  return true;
}

bool NQueen::solveRow(unsigned CurRow) {
  if (CurRow == MaxDim) {
#ifndef ONLINE_JUDGE
    dump();
#endif
    SolutionNumber += 1;
    return true;
  }

  for (unsigned j = 0; j < MaxDim; ++j) {
    if (BrokenTable[CurRow][j])
      continue; // Broken slot

    if (!Column[j] && checkDiagonal(CurRow, j)) {
      // No one use this column.
      Column[j] = true;
      RealTable[CurRow][j] = true;
      solveRow(CurRow + 1);

      // back-tracking
      Column[j] = false;
      RealTable[CurRow][j] = false;
    }
  }

  return false;
}

void NQueen::solve() {
  solveRow(0);
}

unsigned NQueen::getSolutionNumber() {
  return SolutionNumber;
}
