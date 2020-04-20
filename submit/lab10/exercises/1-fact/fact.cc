#include "fact.hh"

unsigned fact(unsigned n) {
	if (n == 0) return 1;
  return (n <= 1) ? n : n * fact(n - 1);
}
