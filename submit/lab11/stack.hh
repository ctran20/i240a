#ifndef STACK_HH
#define STACK_HH

class Stack
{
public:
	void Push(int(&arr)[16], int delim);
	int Pop(int(&arr)[16], int delim);
	bool IsEmpty(int arr[]);
	int Size(int arr[]);
	//Error();
};

#endif //!STACK_HH