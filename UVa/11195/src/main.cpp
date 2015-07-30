#include "NQueen.h"

int main() {
  unsigned Dim;
  NQueen Queen;
  unsigned CaseID = 1;
  while (std::cin >> Dim) {
    if (Dim == 0)
      break;

    Queen.resetDim(Dim);
    std::string str;
    std::getline(std::cin, str);        // Move pivot to next line
    for (unsigned i = 0; i < Dim; ++i) {
      std::getline(std::cin, str);
      for (unsigned j = 0; j < Dim; ++j) {
        if (str[j] == '*')
          Queen.setBroken(i, j);
      }
    }

    Queen.solve();
    unsigned result = Queen.getSolutionNumber();
    std::cout << "Case " << CaseID++ << ": " << result << std::endl;
  }
  return 0;
}
