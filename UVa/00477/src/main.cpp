//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

struct Point {
  double X;
  double Y;

  Point(double a, double b) : X(a), Y(b) {}
};

struct DataSet {
  bool IsRec;
  double X1, Y1;
  union {
    double X2;
    double R;
  };
  double Y2;

  DataSet(double a, double b, double c, double d)
    : IsRec(true), X1(a), Y1(b), X2(c), Y2(d) {}
  DataSet(double a, double b, double r)
    : IsRec(false), X1(a), Y1(b), R(r) {}

  bool contains(const Point &P) const {
    if (IsRec) {
      if (P.X > X1 && P.Y < Y1 && P.X < X2 && P.Y > Y2)
        return true;
    } else {
      double DiffX = std::abs(P.X - X1);
      double DiffY = std::abs(P.Y - Y1);
      if (std::sqrt(DiffX*DiffX + DiffY*DiffY) < R)
        return true;
    }
    return false;
  }
};

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  // Implement here.
  std::string Input;
  std::vector<DataSet> Data;
  std::vector<Point> Pnts;
  while (std::getline(is, Input)) {
    if (Input[0] == '*') {
      continue;
    } else if (Input[0] == 'r') {
      char C;
      double X1, Y1, X2, Y2;
      std::stringstream ss;
      ss << Input;
      ss >> C >> X1 >> Y1 >> X2 >> Y2;
      Data.emplace_back(X1, Y1, X2, Y2);
    } else if (Input[0] == 'c') {
      char C;
      double X1, Y1, R;
      std::stringstream ss;
      ss << Input;
      ss >> C >> X1 >> Y1 >> R;
      Data.emplace_back(X1, Y1, R);
    } else {
      double X, Y;
      std::stringstream ss;
      ss << Input;
      ss >> X >> Y;
      if (std::abs(X - 9999.9) < DBL_EPSILON &&
          std::abs(Y - 9999.9) < DBL_EPSILON)
        break;
      Pnts.emplace_back(X, Y);
    }
  }

#if 0
  for (const auto &D : Data) {
    if (D.IsRec)  os << std::fixed << "(" << D.X1 << "," << D.Y1 << "), (" << D.X2 << "," << D.Y2 << ")\n";
    else  os << std::fixed << "(" << D.X1 << "," << D.Y1 << "), R = " << D.R << "\n";
  }
  for (const auto &P : Pnts) {
    os << std::fixed << "Point: (" << P.X << "," << P.Y << ")\n";
  }
#endif

  REP (i, 0, Pnts.size()) {
    const auto &P = Pnts[i];
    bool Printed = false;
    REP (j, 0, Data.size()) {
      const auto &D = Data[j];
      if (D.contains(P)) {
        os << "Point " << i+1 << " is contained in figure " << j+1 << "\n";
        Printed = true;
      }
    }

    if (!Printed) os << "Point " << i+1 << " is not contained in any figure\n";
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
