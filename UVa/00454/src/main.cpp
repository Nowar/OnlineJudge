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
  std::map<std::string, std::vector<std::string>> Anagrams;
  std::getline(is, Input);
  std::stringstream ss;
  ss << Input;
  int Count;  ss >> Count;
  std::getline(is, Input);
  while (Count-- > 0) {
    while (std::getline(is, Input)) {
      std::string Pivot = Input;
      std::sort(ALL(Pivot));
      size_t pos = Pivot.find_last_of(' ');
      if (pos != std::string::npos)
        Pivot = Pivot.substr(pos+1, Pivot.size()-pos-1);

      Anagrams[Pivot].push_back(Input);
      os << "Pivot: " << Pivot << ", Input: " << Input << "\n";
    }

    for (auto A : Anagrams) {
      std::sort(ALL(A.second));
    }

    for (auto A : Anagrams) {
      if (A.second.size() > 1) {
        REP (i, 0, A.second.size()) {
          REP (j, i+1, A.second.size()) {
            os << A.second[i] << " = " << A.second[j] << "\n";
          }
        }
      }
    }

    if (Count != 0) os << "\n";
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
