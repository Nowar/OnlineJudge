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
  std::string Input;
  is >> Count;  std::getline(is, Input);
  REP (i, 0, Count) {
    os << "Case #" << i+1 << ":\n";
    std::getline(is, Input);
    std::vector<char> Matrix;
    Matrix.resize(10000);
    auto Iter = std::copy_if(ALL(Input), Matrix.begin(), [](char c) {  return ::isalpha(c);  });
    UASSERT (Iter - Matrix.begin() < 10000);
    Matrix.resize(Iter - Matrix.begin());
    unsigned long K = ::sqrt(Matrix.size());
    if (K * K != Matrix.size()) {
      os << "No magic :(\n";
      continue;
    }

    DEBUG (
      REP (i, 0, K) {
        REP (j, 0, K) {
          os << Matrix[i * K + j] << " ";
        }
        os << "\n";
      }
      os << "\n";
          );

    std::vector<char> ReadA(Matrix.begin(), Matrix.end());
    std::vector<char> ReadB(Matrix.rbegin(), Matrix.rend());
    std::vector<char> ReadC;  ReadC.reserve(Matrix.size());
    std::vector<char> ReadD;  ReadD.reserve(Matrix.size());
    REP (j, 0, K) {
      REP (i, 0, K) {
        auto Idx = i * K + j;
        ReadC.push_back(Matrix[Idx]);
        ReadD.push_back(Matrix[Matrix.size() - 1 - Idx]);
      }
    }

    if (ReadA == ReadB && ReadC == ReadD &&
        ReadA == ReadC)
      os << K << "\n";
    else
      os << "No magic :(\n";
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
