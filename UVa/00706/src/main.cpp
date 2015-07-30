#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <vector>

const unsigned kMaxRow = 23;    // 2s+3
const unsigned kMaxCol = 12 * 9;    // s+2

void printDisplay(const unsigned char (&Display)[kMaxRow][kMaxCol], unsigned s, unsigned FinalCol) {
  for (unsigned i = 0, e = 2*s+3; i != e; ++i) {
    for (unsigned j = 0; j != FinalCol; ++j) {
      std::cout << Display[i][j];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void fillupDisplay(unsigned char (&Display)[kMaxRow][kMaxCol], unsigned s, unsigned DigitNumber,
                   unsigned BaseCol) {
  // Left-up corner
  // Always Empty

  // Up
  {
    unsigned char c = ' ';
    switch (DigitNumber) {
    case 0:
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      c = '-';
      break;
    }

    for (unsigned j = BaseCol + 1, count = 0; count != s; ++j, ++count)
      Display[0][j] = c;
  }

  // Right-up corner
  // Always Empty


  // Left-upper
  {
    unsigned char c = ' ';
    switch (DigitNumber) {
    case 0:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
      c = '|';
      break;
    }

    for (unsigned i = 1, count = 0; count != s; ++i, ++count)
      Display[i][BaseCol] = c;
  }

  // Right-upper
  {
    unsigned char c = ' ';
    switch (DigitNumber) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
      c = '|';
      break;
    }

    for (unsigned i = 1, count = 0; count != s; ++i, ++count)
      Display[i][BaseCol+s+1] = c;
  }

  // Left-middle corner
  // Always Empty

  // Middle
  {
    unsigned char c = ' ';
    switch (DigitNumber) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
      c = '-';
      break;
    }

    for (unsigned j = BaseCol + 1, count = 0; count != s; ++j, ++count)
      Display[s+1][j] = c;
  }

  // Right-middle corner
  // Always Empty

  // Left-down
  {
    unsigned char c = ' ';
    switch (DigitNumber) {
    case 0:
    case 2:
    case 6:
    case 8:
      c = '|';
      break;
    }

    for (unsigned i = s+2, count = 0; count != s; ++i, ++count)
      Display[i][BaseCol] = c;
  }

  // Right-down
  {
    unsigned char c = ' ';
    switch (DigitNumber) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      c = '|';
      break;
    }

    for (unsigned i = s+2, count = 0; count != s; ++i, ++count)
      Display[i][BaseCol+s+1] = c;
  }

  // Left-down corner
  // Always Empty

  // Down
  {
    unsigned char c = ' ';
    switch (DigitNumber) {
    case 0:
    case 2:
    case 3:
    case 5:
    case 6:
    case 8:
    case 9:
      c = '-';
      break;
    }

    for (unsigned j = 1, count = 0; count != s; ++j, ++count)
      Display[2*s+2][BaseCol+j] = c;
  }

  // Right-down corner
  // Always Empty
}

int main() {
  unsigned char Display[kMaxRow][kMaxCol];
  std::string Number;
  unsigned s;        // 1 <= s <= 10, 0 <= n <= 99,999,999
  while (std::cin >> s >> Number) {
    if (s == 0)
      break;

    memset(Display, ' ', kMaxRow*kMaxCol);
    unsigned BaseCol = 0;
    for (unsigned i = 0, e = Number.size(); i != e; ++i) {
      std::string Digit = Number.substr(i, 1);
      unsigned DigitNumber;
      std::stringstream ss;
      ss << Digit;
      ss >> DigitNumber;
#ifndef ONLINE_JUDGE
      std::cerr << "DigitStr: " << Digit << std::endl;
      std::cerr << "Digit: " << DigitNumber << std::endl;
#endif
      fillupDisplay(Display, s, DigitNumber, BaseCol);
      BaseCol += (s + 2) + 1;
    }
    printDisplay(Display, s, BaseCol - 1);
  }
  return 0;
}
