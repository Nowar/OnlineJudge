//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

static void stepOneDay(int &M, int &D, int &Y) {
  int Days[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  D += 1;
  if ((Y % 4 == 0 && Y % 100) || Y % 400 == 0) Days[2] = 29;
  if (D > Days[M])  {
    D = 1;
    if (++M == 13) {
      M = 1;
      Y += 1;
    }
  }
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  int Count;
  is >> Count;
  REP (i, 0, Count) {
    os << i+1 << " ";
    std::string Input;
    is >> Input;
    auto MStr = Input.substr(0, 2);
    auto DStr = Input.substr(2, 2);
    auto YStr = Input.substr(4);
    std::stringstream ss;
    int M, D, Y;
    ss << MStr; ss >> M; ss.clear();
    ss << DStr; ss >> D; ss.clear();
    ss << YStr; ss >> Y;

    REP (i, 0, 280)
      stepOneDay(M, D, Y);

    os << std::setw(2) << std::setfill('0') << M << "/";
    os << std::setw(2) << std::setfill('0') << D << "/";
    os << std::setw(2) << std::setfill('0') << Y << " ";
#if 0
    // The input < 1992 cannot convert to time_t, seems the implementation issue.
    auto TimeInfo = std::tm();
    TimeInfo.tm_mday = D;
    TimeInfo.tm_mon = M-1;
    TimeInfo.tm_year = Y-1990;
    auto Time = std::mktime(&TimeInfo);
    UASSERT (Time != -1);

    std::chrono::duration<long> InitStep(Time);
    std::chrono::duration<long, std::ratio<24*60*60>> Step(280);
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<long>> TP(InitStep);
    TP += Step;
    Time = TP.time_since_epoch().count();
    auto *ResultInfo = std::localtime(&Time);
    M = ResultInfo->tm_mon+1;
    D = ResultInfo->tm_mday;
    Y = ResultInfo->tm_year+1990;
    os << std::setw(2) << std::setfill('0') << M << "/";
    os << std::setw(2) << std::setfill('0') << D << "/";
    os << std::setw(2) << std::setfill('0') << Y << " ";
#endif

    const char *Str[12] = { "capricorn", "aquarius", "pisces", "aries", "taurus",
                            "gemini", "cancer", "leo", "virgo", "libra",
                            "scorpio", "sagittarius"};
    if (M == 1) {
      if (D >= 21)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 2) {
      if (D >= 20)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 3) {
      if (D >= 21)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 4) {
      if (D >= 21)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 5) {
      if (D >= 22)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 6) {
      if (D >= 22)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 7) {
      if (D >= 23)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 8) {
      if (D >= 22)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 9) {
      if (D >= 24)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 10) {
      if (D >= 24)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 11) {
      if (D >= 23)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else if (M == 12) {
      if (D >= 23)  os << Str[M%12] << "\n";
      else  os << Str[(M+11)%12] << "\n";
    } else {
      UASSERT (0);
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
