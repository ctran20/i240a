#ifndef OUT_HH_
#define OUT_HH_

#include <vector>

/** Output a line containing "FOUND" if arg is found in [begin, end),
 *  otherwise output "NOT FOUND"..
 */
template <typename Iterator>
void loopFn(Iterator begin, Iterator end, int arg) {
	for (auto p = begin; p != end; ++p) {
		if (arg == *p) {
			std::cout << "FOUND!" << std::endl;
			return;
		}
	}
	std::cout << "NOT FOUND!" << std::endl;
}

/** Exactly like loopFn() but no loops should be used */
template <typename Iterator>
void noLoopFn(Iterator begin, Iterator end, int arg) {
	if (std::find(begin, end, arg) != end) {
		std::cout << "FOUND!" << std::endl;
	}
	else {
		std::cout << "NOT FOUND!" << std::endl;
	}
}

#endif //ifndef OUT_HH_
