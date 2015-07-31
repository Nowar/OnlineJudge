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
  std::map<std::string, std::set<std::string>> Anagrams;
  std::getline(is, Input);
  std::stringstream ss;
  ss << Input;
  int Count;  ss >> Count;
  std::getline(is, Input);
  while (Count-- > 0) {
    while (std::getline(is, Input), !Input.empty()) {
      std::string Pivot = Input;
      std::sort(ALL(Pivot));
      size_t pos = Pivot.find_last_of(' ');
      if (pos != std::string::npos)
        Pivot = Pivot.substr(pos+1, Pivot.size()-pos-1);
      Anagrams[Pivot].insert(Input);
    }

    std::vector<std::string> Container;
    Container.reserve(128);
    for (auto A : Anagrams) {
      if (A.second.size() > 1) {
        std::vector<std::string> Results(A.second.begin(), A.second.end());
        REP (i, 0, Results.size()) {
          REP (j, i+1, Results.size()) {
            std::string S = Results[i] + " = " + Results[j];
            Container.push_back(S);
          }
        }
      }
    }
    std::sort(ALL(Container));
    for_each(ALL(Container), [&os](const std::string &S) { os << S << "\n"; });

    if (Count != 0) os << "\n";
    Anagrams.clear();
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
