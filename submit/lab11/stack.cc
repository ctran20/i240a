#include <stack.hh>

void Stack::Push(int (&arr)[16], int delim) {
	for (int i = 0; arr[i] != 0; i++) {
		if (arr[i + 1] == 0) {
			arr[i+1] = delim;
			return;
		}
	}
}

int Stack::Pop(int (&arr)[16], int delim) {
	for (int i = 0; arr[i] != 0; i++) {
		if (arr[i + 1] == 0) {
			if (arr[i] == -delim) {
				int temp = arr[i];
				arr[i] = 0;
				return temp;
			}
			else {
				std::cout << "unbalanced at argument" << std::endl;
				return 0;
			}
		}
	}
}

bool Stack::IsEmpty(int arr[]) {
	if (arr[0] == 0) {
		return true;
	}
	return false;
}

int Stack::Size(int arr[])  {
	int i = 0;
	while (arr[i] != 0) {
		i++;
	}
	return i;
}