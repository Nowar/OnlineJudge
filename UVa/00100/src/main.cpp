#include <algorithm>
#include <iostream>
#include <map>
#include <cassert>

std::map<unsigned, unsigned> CountMap;

unsigned recur(unsigned cur) {
  if (cur == 1)
    return 1;

  unsigned ret = CountMap[cur];
  if (ret != 0)
    return ret;

  if (cur % 2)
    ret = recur(3 * cur + 1) + 1;
  else
    ret = recur(cur / 2) + 1;

#ifndef ONLINE_JUDGE
      assert (CountMap[cur] == 0 ||
              CountMap[cur] == ret);
#endif
  CountMap[cur] = ret;
  return ret;
}

int main() {
  unsigned a, b;
  CountMap[1u] = 1u;
  while (std::cin >> a >> b) {
    std::cout << a << " " << b << " ";
    if (a > b)
      std::swap(a, b);
    unsigned Max = 0;
    for (unsigned n = a; n <= b; ++n) {
      unsigned Count = recur(n);
      if (Count > Max)
        Max = Count;
#ifndef ONLINE_JUDGE
      std::cerr << "After " << n << ": Max = " << Max << std::endl;
#endif
    }
    std::cout << Max << "\n";
  }
  return 0;
}
