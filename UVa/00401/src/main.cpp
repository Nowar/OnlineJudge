#include <iostream>
#include <map>
#include <string>
#include <algorithm>

typedef std::map<char, char> TableTy;

void createReverseTable(TableTy &T) {
	for (unsigned i = 'A', e = 'Z'; i != e; ++i) {
		T[i] = '?';
	}
	for (unsigned i = '1', e = '9'; i != e; ++i) {
		T[i] = '?';
	}
	T['A'] = 'A';
	T['E'] = '3';	T['3'] = 'E';
	T['H'] = 'H';
	T['I'] = 'I';
	T['J'] = 'L';	T['L'] = 'J';
	T['M'] = 'M';
	T['O'] = 'O';
	T['S'] = '2';	T['2'] = 'S';
	T['T'] = 'T';
	T['U'] = 'U';
	T['U'] = 'U';
	T['V'] = 'V';
	T['W'] = 'W';
	T['X'] = 'X';
	T['Y'] = 'Y';
	T['Z'] = '5';	T['5'] = 'Z';
	T['1'] = '1';
	T['8'] = '8';
}

int main() {
	TableTy Table;
	createReverseTable(Table);
	std::string InputStr;
	while (std::getline(std::cin, InputStr)) {
    bool IsPalindrome = true;
    bool IsMirrored = true;
    for (int i = 0, j = InputStr.size()-1; i<j; ++i, --j) {
      if (InputStr[i] != InputStr[j]) {
        IsPalindrome = false;
        break;
      }
    }
    for (int i = 0, j = InputStr.size()-1; i<=j; ++i, --j) {
      if (InputStr[i] != Table[InputStr[j]]) {
        IsMirrored = false;
        break;
      }
    }

		std::cout << InputStr;
		if (IsPalindrome && IsMirrored)
			std::cout << " -- is a mirrored palindrome.\n\n";
		else if (IsPalindrome)
			std::cout << " -- is a regular palindrome.\n\n";
		else if (IsMirrored)
			std::cout << " -- is a mirrored string.\n\n";
		else
			std::cout << " -- is not a palindrome.\n\n";
  }
  return 0;
}
