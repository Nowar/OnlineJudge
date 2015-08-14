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
  std::string Ignore;
  while (std::getline(is, Input)) {
    bool Failed = false;
    os << Input << "\n";
    std::stringstream ss;
    ss << Input;
    int A = -1, B = -1;
    char Op = 0;
    ss >> Ignore;
    {
      std::stringstream iss;
      iss << Ignore;
      iss >> A;
      if (iss.fail())  {
        Failed = true;
        os << "first number too big\n";
      }
    }
    ss >> Op;
    ss >> Ignore;
    {
      std::stringstream iss;
      iss << Ignore;
      iss >> B;
      if (iss.fail())  {
        Failed = true;
        os << "second number too big\n";
      }
    }

    long long Result = 0;
    if (Op == '+') {
      Result = static_cast<long long>(A) + B;
    } else if (Op == '*') {
      Result = static_cast<long long>(A) * B;
    } else {
      continue;
    }

    if (Failed) {
      if (A == 0 || B == 0)
        continue; // One input invalid, but another one is zero
    } else {
      if ((Result & 0x7fffffff) == Result)
        continue;
    }
    os << "result too big\n";
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
