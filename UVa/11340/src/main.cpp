//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static void runUVa_2(std::istream &is, std::ostream &os) {
  int Count;
  std::string Input;
  is >> Count;
  std::getline(is, Input);
  std::map<char, int> MoneyMapper;
  while (Count-- > 0) {
    std::getline(is, Input);
    std::stringstream ss;
    ss << Input;
    char C; int N;
    ss >> C >> N;
    MoneyMapper[C] = N;
  }
  is >> Count;
  std::getline(is, Input);
  int64_t Money = 0;
  while (Count-- > 0) {
    std::getline(is, Input);
    for (auto C : Input)
      Money += MoneyMapper[C];
  }
  os << Money / 100 << ".";
  Money %= 100;
  if (Money < 10) os << 0;
  os << Money << "$\n";
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  int Count;
  is >> Count;
  std::string Input;
  std::getline(is, Input);
  while (Count-- > 0)
    runUVa_2(is, os);
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
