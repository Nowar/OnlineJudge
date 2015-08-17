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
  // p ∗ e^−x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x^2 + u = 0
  // 0 ≤ x ≤ 1
  // p, q, r, s, t and u (where 0 ≤ p, r ≤ 20 and −20 ≤ q, s, t ≤ 0)

  // if x: 0 -> 1
  // p * e^-x   => smaller
  // q * sin(x) => smaller
  // r * cos(x) => smaller
  // s * tan(x) => smaller
  // t * x^2    => smaller
  // What a coincidence!

  int p, q, r, s, t, u;
  while (is >> p >> q >> r >> s >> t >> u) {
    double min = 0.0, max = 1.0, mid;
    auto MinVal = p * std::exp(-min) +
                  q * std::sin(min) +
                  r * std::cos(min) +
                  s * std::tan(min) +
                  t * min * min +
                  u;
    auto MaxVal = p * std::exp(-max) +
                  q * std::sin(max) +
                  r * std::cos(max) +
                  s * std::tan(max) +
                  t * max * max +
                  u;
    if (MinVal < 0 || MaxVal > 0) {
      os << "No solution\n";
      continue;
    }

    while (max - min > DBL_EPSILON) {
      mid = (min + max) / 2;
      auto MidVal = p * std::exp(-mid) +
                    q * std::sin(mid) +
                    r * std::cos(mid) +
                    s * std::tan(mid) +
                    t * mid * mid +
                    u;
      UASSERT (MinVal >= MidVal && MidVal >= MaxVal);
      if (MidVal > 0)
        min = mid;
      else if (MidVal < 0)
        max = mid;
      else
        break;
    }
    os << std::fixed << std::setprecision(4) << mid << "\n";
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
