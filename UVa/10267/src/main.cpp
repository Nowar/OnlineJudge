#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <vector>
#include <queue>
#include <utility>

static const int kMax = 250;    // 1 ~ 250
static unsigned CurrentM;
static unsigned CurrentN;

void handleCommand(char (&Table)[kMax+2][kMax+2], const std::string &Input) {
  std::stringstream ss;
  char Cmd;
  ss << Input;
  ss >> Cmd;
  unsigned X, Y, X1, Y1, X2, Y2;
  char C;
  std::string Name;
  switch (Cmd) {
  default:
    return;
  case 'I':
    ss >> CurrentN >> CurrentM;
    for (unsigned i = 1; i < CurrentM+1; ++i) {
      for (unsigned j = 1; j < CurrentN+1; ++j) {
        Table[i][j] = 'O';
      }
    }
    break;
  case 'C':
    for (unsigned i = 1; i < CurrentM+1; ++i) {
      for (unsigned j = 1; j < CurrentN+1; ++j) {
        Table[i][j] = 'O';
      }
    }
    break;
  case 'L':
    ss >> Y >> X >> C;
    Table[X][Y] = C;
    break;
  case 'V':
    ss >> X >> Y1 >> Y2 >> C;
    if (Y1 > Y2)  std::swap(Y1, Y2);
    for (unsigned i = Y1; i <= Y2; ++i)
      Table[i][X] = C;
    break;
  case 'H':
    ss >> X1 >> X2 >> Y >> C;
    if (X1 > X2)  std::swap(X1, X2);
    for (unsigned j = X1; j <= X2; ++j)
      Table[Y][j] = C;
    break;
  case 'K':
    ss >> Y1 >> X1 >> Y2 >> X2 >> C;
    for (unsigned i = X1; i <= X2; ++i)
      for (unsigned j = Y1; j <= Y2; ++j)
        Table[i][j] = C;
    break;
  case 'F': {
    ss >> Y >> X >> C;
    char OldC = Table[X][Y];
    std::queue <std::pair<unsigned, unsigned>> Queue;
    bool Visited[kMax+2][kMax+2] = {};
    Queue.push(std::make_pair(X, Y));
    Visited[X][Y] = true;
    while (!Queue.empty()) {
      auto CurXY = Queue.front();
      Visited[CurXY.first][CurXY.second] = true;
      Queue.pop();
      if (Table[CurXY.first][CurXY.second] == OldC) {
        Table[CurXY.first][CurXY.second] = C;
        if (!Visited[CurXY.first - 1][CurXY.second] && CurXY.first > 1) {
          Visited[CurXY.first-1][CurXY.second] = true;
          Queue.push(std::make_pair(CurXY.first - 1, CurXY.second));
        }
        if (!Visited[CurXY.first + 1][CurXY.second] && CurXY.first < 250) {
          Visited[CurXY.first+1][CurXY.second] = true;
          Queue.push(std::make_pair(CurXY.first + 1, CurXY.second));
        }
        if (!Visited[CurXY.first][CurXY.second - 1] && CurXY.second > 1) {
          Visited[CurXY.first][CurXY.second-1] = true;
          Queue.push(std::make_pair(CurXY.first, CurXY.second - 1));
        }
        if (!Visited[CurXY.first][CurXY.second + 1] && CurXY.second < 250) {
          Visited[CurXY.first][CurXY.second+1] = true;
          Queue.push(std::make_pair(CurXY.first, CurXY.second + 1));
        }
      }
    }
    break;
  }
  case 'S':
    ss >> Name;
    std::cout << Name << std::endl;
    for (unsigned i = 1; i <= CurrentM; ++i) {
      for (unsigned j = 1; j <= CurrentN; ++j) {
        std::cout << Table[i][j];
      }
      std::cout << std::endl;
    }
    break;
  case 'X':
    assert ("Should not be here");
    break;
  }
}

int main() {
  char Table[kMax + 2][kMax + 2];
  std::string Input;
  while (std::getline(std::cin, Input)) {
    if (Input == "X")
      break;
    handleCommand(Table, Input);
  }
  return 0;
}
