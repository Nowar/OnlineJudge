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
#include <iomanip>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
// C
#include <cassert>
#include <cstring>
#include <cstdio>

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

// Define your data structure here.

#endif // UVA_H
