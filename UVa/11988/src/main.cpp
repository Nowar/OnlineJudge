//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  std::string Input;
  while (std::getline(is , Input)) {
    std::vector <std::string> Head;
    std::vector <std::string> Tail;
    Head.reserve(256);
    Tail.reserve(256);
    bool IsFront = false;

    size_t Current = 0;
    size_t Found = 0;
    do {
      Found = Input.find_first_of("[]", Current);
      std::string S = Input.substr(Current, Found-Current);
      if (IsFront)
        Head.push_back(S);
      else
        Tail.push_back(S);

      DEBUG ( os << "Extract: " << S << "\n";);

      if (Found == std::string::npos)
        break;

      if (Input[Found] == '[')
        IsFront = true;
      else
        IsFront = false;

      Current = Found+1;
    } while (true);

    for (auto i = Head.rbegin(), e = Head.rend(); i != e; ++i)
      os << *i;
    ITERATOR_REP (i, e, Tail)
      os << *i;
    os << "\n";
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
