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
		std::string ReverseStr {InputStr.rbegin(), InputStr.rend()};
		bool IsPalindrome = (InputStr == ReverseStr);
		std::for_each(ReverseStr.begin(), ReverseStr.end(), [&Table](char &c) {
			c = Table[c];
		});
		bool IsMirrored = (InputStr == ReverseStr &&
		                   ReverseStr.find('?') == std::string::npos);

		std::cout << InputStr;
		if (IsPalindrome && IsMirrored)
			std::cout << " -- is a mirrored palindrome.";
		else if (IsPalindrome)
			std::cout << " -- is a regular palindrome.";
		else if (IsMirrored)
			std::cout << " -- is a mirrored string.";
		else
			std::cout << " -- is not a palindrome.";

#ifndef ONLINE_JUDGE
		std::cout << std::endl;
		std::cout << InputStr << " " << ReverseStr << std::endl;
#endif
		std::cout << std::endl << std::endl;
	}
}
