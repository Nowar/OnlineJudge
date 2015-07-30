#include "NQueen.h"

int main() {
  unsigned Sum, Dim;
  unsigned CaseID = 1;
  NQueen Queen;
  while (std::cin >> Sum) {
    if (Sum == 0)
      break;
    std::cin >> Dim;

    Queen.resetSum(Sum);
    Queen.resetDim(Dim);
    Queen.solve();
    unsigned result = Queen.getMinSurface();
    std::cout << "Case " << CaseID++ << ": ";
    std::cout << ((Queen.getSolutionNumber() == 0) ? 0 : result) << std::endl;
  }
  return 0;
}
