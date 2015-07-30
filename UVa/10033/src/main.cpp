#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <vector>

unsigned run(unsigned (&Mem)[1000], unsigned (&Reg)[10]) {
  unsigned Cycles = 0;
  unsigned PC = 0;
  while (true) {
    Cycles += 1;
    unsigned Insn = Mem[PC++];
    unsigned LastBit = Insn % 10;
    Insn /= 10;
    unsigned MiddleBit = Insn % 10;
    Insn /= 10;

    switch (Insn) {
    case 1:
      return Cycles;
    case 2:
      Reg[MiddleBit] = LastBit;
      break;
    case 3:
      Reg[MiddleBit] = (Reg[MiddleBit] + LastBit) % 1000;
      break;
    case 4:
      Reg[MiddleBit] = (Reg[MiddleBit] * LastBit) % 1000;
      break;
    case 5:
      Reg[MiddleBit] = Reg[LastBit];
      break;
    case 6:
      Reg[MiddleBit] = (Reg[MiddleBit] + Reg[LastBit]) % 1000;
      break;
    case 7:
      Reg[MiddleBit] = (Reg[MiddleBit] * Reg[LastBit]) % 1000;
      break;
    case 8:
      Reg[MiddleBit] = Mem[Reg[LastBit]];
      break;
    case 9:
      Mem[Reg[LastBit]] = Reg[MiddleBit];
      break;
    case 0:
      if (Reg[LastBit] != 0)
        PC = Reg[MiddleBit];
      break;
    }
#ifndef ONLINE_JUDGE
    for (unsigned i = 0; i < 10; ++i) {
      assert (Reg[i] < 1000);
    }
    for (unsigned i = 0; i < 1000; ++i) {
      assert (Mem[i] < 1000);
    }
#endif
  }
}

int main() {
  unsigned Mem[1000] = {};
  unsigned Reg[10] = {};
  unsigned Cases;
  std::cin >> Cases;
  std::string Input;
  std::getline(std::cin, Input);
  std::getline(std::cin, Input);
  for (unsigned i = 0; i < Cases; ++i) {
    unsigned Count = 0;
    while (std::getline(std::cin, Input)) {
      if (Input.empty())
        break;
      std::stringstream ss;
      ss << Input;
#ifndef ONLINE_JUDGE
      assert (Input.size() == 3);
#endif
      ss >> Mem[Count++];
    }

    unsigned Cycles = run(Mem, Reg);

    std::cout << Cycles << "\n";
    if (i != Cases-1)
      std::cout << "\n";

    std::fill(Mem, Mem+1000, 0);
    std::fill(Reg, Reg+10, 0);
  }
  return 0;
}
