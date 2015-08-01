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
  int Day, DD, MM, YY;
  while (is >> Day >> DD >> MM >> YY, Day != 0 && DD != 0 && MM != 0 && YY != 0) {
    std::tm TimeInfo = std::tm();
    TimeInfo.tm_mday = DD;
    TimeInfo.tm_mon = MM - 1;
    TimeInfo.tm_year = YY - 1900;
    time_t Time = std::mktime(&TimeInfo);

    typedef std::chrono::duration<long> DurationSecType;
    typedef std::chrono::duration<long, std::ratio<24*60*60>> DurationDayType;
    typedef std::chrono::time_point<std::chrono::steady_clock, DurationSecType> TimePointType;
    DurationSecType InitStep(Time);
    DurationDayType Step(Day);
    TimePointType TP(InitStep);
    TP += Step;
    Time = TP.time_since_epoch().count();
    const std::tm *CurTimeInfo = std::localtime(&Time);
    os << CurTimeInfo->tm_mday << " " << CurTimeInfo->tm_mon+1 << " " << CurTimeInfo->tm_year+1900 << "\n";
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
