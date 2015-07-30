//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static int DNA[10];
static int Dishes[42];

static void mutateDNA() {
  int Tmp[42];
  memcpy(Tmp, Dishes, sizeof(int)*42);
  for (int i = 1; i <= 40; ++i) {
    Dishes[i] = DNA[Tmp[i-1] + Tmp[i] + Tmp[i+1]];
  }
}

static void printDNA() {
  for (int i = 1; i <= 40; ++i) {
    switch (Dishes[i]) {
    case 0:
      std::cout << ' ';
      break;
    case 1:
      std::cout << '.';
      break;
    case 2:
      std::cout << 'x';
      break;
    case 3:
      std::cout << 'W';
      break;
    }
  }
  std::cout << "\n";
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  int count;
  is >> count;
  for (int i = 0; i < count; ++i) {
    for (int i = 0; i < 10; ++i) {
      is >> DNA[i];
    }

    Dishes[20] = 1;
    printDNA();
    for (int i = 1; i < 50; ++i) {
      mutateDNA();
      printDNA();
    }
    if (i != count-1) os << "\n";

    std::fill(Dishes, Dishes+42, 0);
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
