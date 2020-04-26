#include <iostream>
#include <cstring>
#include "stack.hh"

struct DelimMap {
	int delim;
	int encoding;
};
constexpr DelimMap delimEncodings[] = {
  { '(', 1 },
  { ')', -1 },
  { '[', 2 },
  { ']', -2 },
  { '<', 3 },
  { '>', -3 },
  { '{', 4 },
  { '}', -4 },
};
constexpr int delimSize = sizeof(delimEncodings) / sizeof(delimEncodings[0]);

void Push(int(&arr)[16], int delim) {
	for (int i = 0; arr[i] != 0; i++) {
		if (arr[i + 1] == 0) {
			arr[i + 1] = delim;
			return;
		}
	}
}

int Pop(int(&arr)[16], int delim, int pos) {
	if (pos == 0) {
		arr[0] = 0;
	}
	for (int i = 0; arr[i] != 0; i++) {
		if (arr[i + 1] == 0) {
			if (arr[i] == -delim) {
				int temp = arr[i];
				arr[i] = 0;
				return temp;
			}
			else {
				std::cout << "unbalanced at argument " << pos+1 <<std::endl;
				std::exit(1);
			}
		}
	}
	return 0;
}

bool IsEmpty(int arr[]) {
	if (arr[0] == 0) {
		return true;
	}
	std::cout << arr[0] << std::endl;
	return false;
}

int Size(int arr[]) {
	int i = 0;
	while (arr[i] != 0) {
		i++;
	}
	return i;
}

//Return 0 if invalid delim
int getDelimEncoding(char delim)
{
	for (int i = 0; i < delimSize; i++) {
		if (delim == delimEncodings[i].delim) {
			return delimEncodings[i].encoding;
		}
	}
	return 0;
};

int main(int argc, char *argv[]) {
	int stk[16];
	int stkIndex = 0;

	for (int i = 1; i < 16; i++) {
		stk[i] = 0;
	}

	for (int i = 1; i < argc; i++) {
		int delim = getDelimEncoding(argv[i][0]);
		if (strlen(argv[i]) != 1 || delim == 0) {
			std::cout << "invalid delimiter '" << (argv[i]) << "'" << std::endl;
			std::exit(1);
		}
		if (delim > 0) {
			Push(stk, delim);
		}
		else {
			Pop(stk, delim, stkIndex);
		}
		stkIndex++;
	}

	if (stkIndex % 2 == 1) {
		std::cout << "unbalanced at argument " << stkIndex << std::endl;
		std::exit(1);
	}

	return 0;
}

