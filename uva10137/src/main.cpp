#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <iomanip>
#include <cassert>
#include <vector>

#if 0
class Money {
public:
  unsigned Dollar = 0u;
  unsigned Cent = 0u;
public:
  Money(unsigned = 0) {}
};

template <typename T>
struct Less {
  bool operator()(const T&, const T&);
};

template <>
struct Less<Money> {
  bool operator()(const Money &A, const Money &B) {
    return A.Dollar < B.Dollar ||
      (A.Dollar == B.Dollar && A.Dollar < B.Dollar);
  }
};

bool operator<(const Money &A, const Money &B) {
  return Less<Money>()(A, B);
}

Money operator/(const Money &A, unsigned N) {
  Money Result;
  Result.Dollar = A.Dollar / N;
  unsigned Cent = A.Cent;
  if (A.Dollar % N) {
    Cent += (A.Dollar % N) * 10000;
  }
  Result.Cent = Cent / N;
  return Result;
}

Money operator+(const Money &A, const Money &B) {
  Money Result;
  Result.Dollar = A.Dollar + B.Dollar;
  Result.Cent = A.Cent + B.Cent;
  if (Result.Cent > 10000) {
    Result.Cent -= 10000;
    Result.Dollar += 1;
  }
  return Result;
}

Money operator-(const Money &A, const Money &B) {
  Money Result;
  Result.Dollar = A.Dollar - B.Dollar;
  if (A.Cent < B.Cent) {
    Result.Dollar -= 1;
    Result.Cent = A.Cent + 10000 - B.Cent;
  } else {
    Result.Cent = A.Cent - B.Cent;
  }
  return Result;
}

std::istream &operator>>(std::istream &is, Money &M) {
  std::string s;
  is >> s;
  unsigned pos = s.find('.');
  std::string DollarStr = s.substr(0, pos);
  std::string CentStr = s.substr(pos + 1, 2);
  std::stringstream ss;
  ss << DollarStr;
  ss >> M.Dollar;
  ss.clear();   // clear last time EOF flag
  ss << CentStr;
  ss >> M.Cent;
  M.Cent *= 100;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Money &M) {
  os << M.Dollar << ".";
#ifndef ONLINE_JUDGE
  assert (M.Cent < 10000);
  unsigned Cent = M.Cent;
  if (Cent < 1000)
    os << 0;
  if (Cent < 100)
    os << 0;
  if (Cent < 10)
    os << 0;
#else
  unsigned Cent = M.Cent / 100;
  if (Cent < 10)
    os << 0;
#endif
  os << Cent;
  return os;
}

int main() {
  unsigned NStudent;
  while (std::cin >> NStudent) {
    if (NStudent == 0)
      break;

    std::multiset<Money, Less<Money>> AllMoney;
    Money Total = 0;
    for (unsigned i = 0; i < NStudent; ++i) {
      Money M;
      std::cin >> M;
      AllMoney.insert(M);
      Total = Total + M;
    }

    Money Average = Total / NStudent;
    Average.Cent = Average.Cent / 100 * 100;
#ifndef ONLINE_JUDGE
    std::cerr << "\nTotal: " << Total << std::endl;
    std::cerr << "Average: " << Average << std::endl;
#endif
    Money Result = 0;
    for (Money M : AllMoney) {
      if (M < Average) {
        Result = Result + (Average - M);
#ifndef ONLINE_JUDGE
        std::cerr << "Delta: " << Average - M << std::endl;
        std::cerr << "Result: " << Result << std::endl;
#endif
      }
    }
    std::cout << "$" << Result << std::endl;
  }
  return 0;
}
#endif

#if 1
int main() {
  unsigned NStudent;
  while (std::cin >> NStudent) {
    if (NStudent == 0)
      break;

    std::vector<double> AllMoney;
    double Total = 0;
    for (unsigned i = 0; i < NStudent; ++i) {
      double M;
      std::cin >> M;
      AllMoney.push_back(M);
      Total = Total + M;
    }

    double Average = Total / NStudent;
    Average = (double)(long)((Average * 100.0) + 0.5) / 100.0;
#ifndef ONLINE_JUDGE
    std::cerr << "Total: " << Total << std::endl;
    std::cerr << "Average: " << Average << std::endl;
#endif
    double SmallResult = 0, BigResult = 0;
    for (auto M : AllMoney) {
      if (M < Average)
        SmallResult += Average - M;
      else if (M > Average)
        BigResult += M - Average;
    }

#ifndef ONLINE_JUDGE
    std::cerr << "Small Result: " << SmallResult << std::endl;
    std::cerr << "Big Result: " << BigResult << std::endl;
#endif
    double Result = (SmallResult < BigResult) ? SmallResult : BigResult;
    std::cout.precision(2);
    std::cout << std::fixed << "$" << Result << std::endl;
  }
  return 0;
}
#endif
