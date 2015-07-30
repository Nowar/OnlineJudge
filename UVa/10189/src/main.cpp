#include <algorithm>
#include <iostream>
#include <map>
#include <cassert>
#include <vector>
#include <cstring>
#include <utility>

unsigned char MineTable[102][102];
std::vector<std::pair<unsigned, unsigned>> Mines;

void compute() {
  for (auto Mine : Mines) {
    unsigned i = Mine.first;
    unsigned j = Mine.second;
    MineTable[i-1][j-1] += 1;
    MineTable[i-1][j] += 1;
    MineTable[i-1][j+1] += 1;
    MineTable[i][j-1] += 1;
    MineTable[i][j+1] += 1;
    MineTable[i+1][j-1] += 1;
    MineTable[i+1][j] += 1;
    MineTable[i+1][j+1] += 1;
  }
}

void cleanup() {
  memset(MineTable, 0, 102*102);
  Mines.clear();
}

int main() {
  unsigned Row, Col;
  unsigned FieldID = 1;
  bool FirstTime = true;
  while (std::cin >> Row >> Col) {
    if (Row == 0)
      break;
    if (FirstTime)
      FirstTime = !FirstTime;
    else
      std::cout << "\n";
    std::cout << "Field #" << FieldID++ << ":\n";
    for (unsigned i = 1; i <= Row; ++i) {
      for (unsigned j = 1; j <= Col; ++j) {
        unsigned char Input;
        std::cin >> Input;
        if (Input == '*') {
          MineTable[i][j] = (unsigned char) 9;
          Mines.push_back(std::make_pair(i, j));
        }
      }
    }

    compute();

    for (unsigned i = 1; i <= Row; ++i) {
      for (unsigned j = 1; j <= Col; ++j) {
        if (MineTable[i][j] > (unsigned char) 8)
          std::cout << "*";
        else
          std::cout << (unsigned int) MineTable[i][j];
      }
      std::cout << "\n";
    }

    cleanup();
  }
  return 0;
}
