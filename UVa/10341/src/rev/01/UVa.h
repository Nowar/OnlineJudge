//==========================================================================//
// Copyright (c) 2010-2015 Wen-Han Gu. All rights reserved.
//
// Author: Wen-Han Gu (a.k.a. Nowar)
// E-mail: wenhan.gu <at> gmail.com
//
// Any advice is welcome. Thank you!
//==========================================================================//
#ifndef UVA_H
#define UVA_H

// Include all headers in here since UVa can only submit one merged file.
// This is not a good behavior but it works.

// C++
#include <algorithm>
#include <bitset>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
// C
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>

#ifndef UASSERT
#ifndef ONLINE_JUDGE
#define UASSERT(expr) assert (expr)
#else
#define UASSERT(expr)
#endif
#endif

#ifndef DEBUG
#ifndef ONLINE_JUDGE
#define DEBUG(expr) do { expr; } while (0)
#else
#define DEBUG(expr)
#endif
#endif

#ifndef REP
#define REP(i, start, end)  for (int i = (int) start; i < (int) end; ++i)
#endif

#ifndef ITERATOR_REP
#define ITERATOR_REP(i, e, X) for (auto i = X.begin(), e = X.end(); i != e; ++i)
#endif

#ifndef ALL
#define ALL(x)  x.begin(), x.end()
#endif

#ifndef INPLACE_UNIQUE
#define INPLACE_UNIQUE(x)   x.resize(std::unique(ALL(x)) - x.begin())
#endif

#ifndef DUMP_ALL
#define DUMP_ALL(os, x)   os << "DUMP_ALL: ";  for (auto i = x.begin(); i < x.end(); ++i)  os << *i << " ";  os << "\n";
#endif

#ifndef ii
#define ii  std::pair<int, int>
#endif

#ifndef vi
#define vi  std::vector<int>
#endif

#ifndef vii
#define vii std::vector<ii>
#endif

// Define your data structure here.

#endif // UVA_H
