//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static int gcd(int a, int b) {
  UASSERT (a > 0 && b > 0);
  int Max = std::max(a, b);
  int Min = std::min(a, b);
  if (Min == 1) return Max;
  while (true) {
    Max %= Min;
    if (Max == 0) return Min;
    std::swap(Max, Min);
  }
}

static int commonWidth(int a, int b) {
  UASSERT (a > 0 && b > 0);
  int Width = 0;
  for ( ; !(a == 0 && b == 0); a /= 10, b /= 10) {
    Width++;
  }
  return Width;
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  std::string Input;
  int Count = 0;
  while (std::getline(is, Input)) {
    int Sum = 0, N = 0;
    std::stringstream ss;
    ss << Input;
    ss >> N;
    if (N == 0) break;
    REP (i, 0, N) {
      int Number;
      ss >> Number;
      Sum += Number;
    }

    int a, b, c;
    a = std::abs(Sum) / N;
    c = N;
    b = std::abs(Sum) - (a * c);

    os << "Case " << ++Count << ":\n";
    if (b == 0) {
      if (Sum < 0)  os << "- ";
      os << a << "\n";
    } else {
      int d = gcd(b, c);
      if (d <= b && d <= c) {
        b /= d;
        c /= d;
      }
      int CommonWidth = commonWidth(b, c);
      if (Sum < 0)  os << "  ";
      for (int i = a; i != 0; i /= 10)  os << " ";
      int Width = 0;
      for (int i = b; i != 0; i /= 10)  Width++;
      REP (i, Width, CommonWidth) os << " ";
      os << b << "\n";
      if (Sum < 0)  os << "- ";
      if (a != 0) os << a;
      REP (i, 0, CommonWidth) os << "-";
      os << "\n";
      if (Sum < 0)  os << "  ";
      for (int i = a; i != 0; i /= 10)  os << " ";
      os << c << "\n";
    }
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
