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
  vi Freq;
  vi Start;
  int Begin = 1;  // Temp counter for recording begin

public:
  void resetSize(int N);
  void setValue(int Idx, int Value);
  void buildHeap();
  int query(int Begin, int End, bool Inclusive = true);
};

void RangeMaxQuery::resetSize(int N) {
  Input.assign(N+1, 0);
  Freq.assign(N+1, 0);
  Start.assign(N+1, 0);
}

void RangeMaxQuery::setValue(int Idx, int Value) {
  Input[Idx] = Value;
  if (Value != Input[Begin]) {
    REP (i, Begin, Idx)
      Freq[i] = Idx - Begin;
    REP (i, Begin, Idx)
      Start[i] = Begin;
    Begin = Idx;
  }
}

void RangeMaxQuery::buildHeap() {
  REP (i, Begin, Input.size())
    Freq[i] = Input.size() - Begin;
  REP (i, Begin, Input.size())
    Start[i] = Begin;
  DUMP_ALL (std::cerr, Input);
  DUMP_ALL (std::cerr, Freq);
  DUMP_ALL (std::cerr, Start);
}
int RangeMaxQuery::query(int Begin, int End, bool Inclusive) {
  DEBUG (std::cerr << "query: [" << Begin << ", " << End << "]\n";);

  UASSERT (Inclusive);
  UASSERT (Begin >= 1 && Begin < Input.size());
  UASSERT (End >= 1 && End < Input.size());

  if (Begin > End)
    return 0;

  if (Input[Begin] == Input[End]) { // Fully in the same region
    return End - Begin + 1;
  }

  int Max = 0;
  if (Start[Begin] != Begin) {  // Partial head
    int Tail = Start[Begin] + Freq[Begin] - 1;
    UASSERT (Input[Begin] == Input[Tail]);
    int HeadMax = query(Begin, Tail);
    Max = std::max(Max, HeadMax);
    DEBUG (std::cerr << "Update max: " << Max << "\n";);
    Begin = Tail + 1;
    DEBUG (std::cerr << "New Begin: " << Begin << "\n";);
  }

  if (Start[End] + Freq[End] - 1 != End) {  // Partial tail
    int Head = Start[End];
    UASSERT (Input[Head] == Input[End]);
    int TailMax = query(Head, End);
    Max = std::max(Max, TailMax);
    DEBUG (std::cerr << "Update max: " << Max << "\n";);
    End = Head - 1;
    DEBUG (std::cerr << "New End: " << End << "\n";);
  }

  if (Begin > End)
    return Max;

  UASSERT (End == Start[End] + Freq[End] - 1);
  UASSERT (Begin == Start[Begin]);
  int Middle = (Begin + End) / 2;
  Middle = Start[Middle] + Freq[Middle] - 1;  // Align middle to the range last.
  DEBUG (std::cerr << "Middle: " << Middle << "\n";);
  if (Middle == End && Middle != Begin)
    Middle = Start[Middle] - 1; // Get rid of infinite loop
  DEBUG (std::cerr << "Middle: " << Middle << "\n";);
  Max = std::max(Max, query(Begin, Middle));
  DEBUG (std::cerr << "Update left-half max: " << Max << "\n";);
  Max = std::max(Max, query(Middle + 1, End));
  DEBUG (std::cerr << "Update right-half max: " << Max << "\n";);
  return Max;
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
