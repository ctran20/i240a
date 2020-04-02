#include "ops.hh"

class Count : public Ops {

public:
	int swapCount = 0;
	int compareCount = 0;

	/** return < 0, == 0, > 0 if a < b, a == b, a > b */
	virtual int compare(int a, int b) {
		swapCount++;
		return a - b;
	};

	/** swap a[i] and a[j] */
	virtual void swap(int a[], int i, int j) {
		compareCount++;
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	};
};
