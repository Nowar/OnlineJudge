//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

enum Blood {
  BLOOD_UNKNOWN,
  BLOOD_OP,
  BLOOD_OM,
  BLOOD_AP,
  BLOOD_AM,
  BLOOD_BP,
  BLOOD_BM,
  BLOOD_ABP,
  BLOOD_ABM
};

static Blood convertStrToBlood(const std::string &S) {
  if (S == "O+")  return BLOOD_OP;
  if (S == "O-")  return BLOOD_OM;
  if (S == "A+")  return BLOOD_AP;
  if (S == "A-")  return BLOOD_AM;
  if (S == "B+")  return BLOOD_BP;
  if (S == "B-")  return BLOOD_BM;
  if (S == "AB+")  return BLOOD_ABP;
  if (S == "AB-")  return BLOOD_ABM;
  return BLOOD_UNKNOWN;
}

static std::string convertBloodToStr(Blood B) {
  if (B == BLOOD_OP)  return "O+";
  if (B == BLOOD_OM)  return "O-";
  if (B == BLOOD_AP)  return "A+";
  if (B == BLOOD_AM)  return "A-";
  if (B == BLOOD_BP)  return "B+";
  if (B == BLOOD_BM)  return "B-";
  if (B == BLOOD_ABP)  return "AB+";
  if (B == BLOOD_ABM)  return "AB-";
  return "";
}

static std::set<Blood> propagate(Blood B1, Blood B2) {
  // TODO
  std::set<Blood> S;
  return {};
}

static std::set<Blood> reversePropagate(Blood BP, Blood BC) {
  // TODO
  std::set<Blood> S;
  return {};
}

static std::string getParent(const std::string &P, const std::string &C) {
  Blood BP = convertStrToBlood(P);
  Blood BC = convertStrToBlood(C);
  std::set<Blood> Result = reversePropagate(BP, BC);
  if (Result.empty())  return "IMPOSSIBLE";
  std::string S;
  if (Result.size() > 1) S += "{";
  bool First = true;
  for (auto B: Result) {
    if (!First)  S += ", ";
    First = false;
    S += convertBloodToStr(B);
  }
  if (C.size() > 1) S += "}";
  return S;
}

static std::string getChild(const std::string &P1, const std::string &P2) {
  Blood B1 = convertStrToBlood(P1);
  Blood B2 = convertStrToBlood(P2);
  std::set<Blood> C = propagate(B1, B2);
  std::string S;
  if (C.size() > 1) S += "{";
  bool First = true;
  for (auto B: C) {
    if (!First)  S += ", ";
    First = false;
    S += convertBloodToStr(B);
  }
  if (C.size() > 1) S += "}";
  return S;
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  std::string P1, P2, C;
  int Count = 0;
  while (is >> P1 >> P2 >> C, P1 != "E" || P2 != "N" || C != "D") {
    os << "Case " << ++Count << ": ";
    if (P1 == "?")
      P1 = getParent(P2, C);
    else if (P2 == "?")
      P2 = getParent(P1, C);
    else
      C = getChild(P1, P2);
    os << P1 << " " << P2 << " " << C << "\n";
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
