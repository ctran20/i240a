#include <cctype>

#include "digit-sum.hh"

int
digitSum(const char* str)
{
	bool wantDigit = true;
	int acc = 0;

	for (const char* p = str; *p; ++p) {
		int c = *p;
		if (isdigit(c)) {
			if (wantDigit) {
				acc += c - '0';
				wantDigit = false;
			}
			else { //expecting +
				break;
			}
		}
		else if (c == '+') {
			if (wantDigit) break;
			wantDigit = true;
		}
		else if (isspace(c)) {
			continue;
		}
		else {
			break;
		}
	}
	return acc;
}
