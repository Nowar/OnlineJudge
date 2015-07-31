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
  int Count;
  while (is >> Count, Count > 0) {
    std::string Input;
    int Current = 1;    // No: 0, +x/-x: 1/2, +y/-y: 3/4, +z/-z: 5/6
    while (--Count > 0) {
      is >> Input;
      if (Input == "No") continue;
      if (Input == "+y") {
        switch (Current) {
        default:
          UASSERT (0);  break;
        case 1:
          Current = 3;  break;
        case 2:
          Current = 4;  break;
        case 3:
          Current = 2;  break;
        case 4:
          Current = 1;  break;
        case 5:
          Current = 5;  break;
        case 6:
          Current = 6;  break;
        }
      } else if (Input == "-y") {
        switch (Current) {
        default:
          UASSERT (0);  break;
        case 1:
          Current = 4;  break;
        case 2:
          Current = 3;  break;
        case 3:
          Current = 1;  break;
        case 4:
          Current = 2;  break;
        case 5:
          Current = 5;  break;
        case 6:
          Current = 6;  break;
        }
      } else if (Input == "+z") {
        switch (Current) {
        default:
          UASSERT (0);  break;
        case 1:
          Current = 5;  break;
        case 2:
          Current = 6;  break;
        case 3:
          Current = 3;  break;
        case 4:
          Current = 4;  break;
        case 5:
          Current = 2;  break;
        case 6:
          Current = 1;  break;
        }
      } else if (Input == "-z") {
        switch (Current) {
        default:
          UASSERT (0);  break;
        case 1:
          Current = 6;  break;
        case 2:
          Current = 5;  break;
        case 3:
          Current = 3;  break;
        case 4:
          Current = 4;  break;
        case 5:
          Current = 1;  break;
        case 6:
          Current = 2;  break;
        }
      }
    }

    switch (Current) {
    default:  UASSERT (0);  break;
    case 1: os << "+x\n"; break;
    case 2: os << "-x\n"; break;
    case 3: os << "+y\n"; break;
    case 4: os << "-y\n"; break;
    case 5: os << "+z\n"; break;
    case 6: os << "-z\n"; break;
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
