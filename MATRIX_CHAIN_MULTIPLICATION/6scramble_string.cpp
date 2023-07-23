// C++ Program to check if a
// given string is a scrambled
// form of another string

#include <bits/stdc++.h>
using namespace std;

bool isScramble(string S1, string S2)
{
	// Strings of non-equal length
	// cant' be scramble strings
	if (S1.length() != S2.length()) {
		return false;
	}

	int n = S1.length();

	// Empty strings are scramble strings
	if (n == 0) {
		return true;
	}

	// Equal strings are scramble strings
	if (S1 == S2) {
		return true;
	}

	// Check for the condition of anagram
	string copy_S1 = S1, copy_S2 = S2;

	sort(copy_S1.begin(), copy_S1.end());
	sort(copy_S2.begin(), copy_S2.end());

	if (copy_S1 != copy_S2) {
		return false;
	}

	for (int i = 1; i < n; i++) {

		if (isScramble(S1.substr(0, i), S2.substr(0, i))
			&& isScramble(S1.substr(i, n - i),
						S2.substr(i, n - i))) {
			return true;
		}
		if (isScramble(S1.substr(0, i),
					S2.substr(n - i, i))
			&& isScramble(S1.substr(i, n - i),
						S2.substr(0, n - i))) {
			return true;
		}
	}
	return false;
}

int main()
{
	string S1 = "coder";
	string S2 = "ocred";

	if (isScramble(S1, S2)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
