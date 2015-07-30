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
  int Month;
  double DownPayment, Loan;
  int Count;
  while (is >> Month >> DownPayment >> Loan >> Count, Month >= 0) {
    double Rates[101];
    std::fill(Rates, Rates+101, 0.0);
    while (Count-- > 0) {
      int Period;
      double Rate;
      is >> Period >> Rate;
      Rates[Period] = Rate;
    }

    double LastRate = 0.0;
    double MonthPaid = Loan / Month;
    double LastTotalPaid = -MonthPaid;
    double LastCarValue = DownPayment + Loan;
    REP (i, 0, Month+1) {
      LastTotalPaid += MonthPaid;
      double LastRate = ((Rates[i] == 0.0) ? (LastRate) : Rates[i]);
      LastCarValue *= (1 - LastRate);
      //DEBUG (os << "Total Paid: " << LastTotalPaid << "\n";
      //       os << "Remaining Loan: " << Loan - LastTotalPaid << "\n";
      //       os << "Last Car Value: " << LastCarValue << "\n");
      if (Loan - LastTotalPaid < LastCarValue) {
        if (i == 1) os << "1 month\n";
        else  os << i << " months\n";
        break;
      }
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
