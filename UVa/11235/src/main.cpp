//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//

#include "UVa.h"

class RangeMaxQuery {
  vi Input;
  vi Heap;
  std::map<int, int> Freq;

public:
  void resetSize(int N);
  void setValue(int Idx, int Value);
  void buildHeap();
  int query(int Begin, int End, bool Inclusive = true);
};

void RangeMaxQuery::resetSize(int N) {
  Input.assign(N+1, 0);
  Heap.assign(N+1, 0);
}

void RangeMaxQuery::setValue(int Idx, int Value) {
  Input[Idx] = Value;
  Freq[Value]++;
}

void RangeMaxQuery::buildHeap() {
  // TODO
}
int RangeMaxQuery::query(int Begin, int End, bool Inclusive) {
  // TODO
}


static bool runUVa_2(std::istream &is, std::ostream &os) noexcept {
  int N, NQ;
  is >> N >> NQ;
  if (N == 0)
    return false;
  RangeMaxQuery RMQ;
  RMQ.resetSize(N);
  REP (i, 1, N+1) {
    int Val;
    is >> Val;
    RMQ.setValue(i, Val);
  }

  RMQ.buildHeap();

  REP (i, 1, NQ+1) {
    int CurI, CurJ;
    is >> CurI >> CurJ;
    os << RMQ.query(CurI, CurJ) << "\n";
  }
  return true;
}

static int runUVa(std::istream &is, std::ostream &os) noexcept {
  while (runUVa_2(is, os))
    continue;
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
