#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

int steps(int start) {
  if (start <= 0)
    throw std::domain_error{"Start must be positive."};
  int steps{0};
  while (start != 1) {
    start = start % 2 == 0 ? start / 2 : 3 * start + 1;
    ++steps;
  }
  return steps;
}

} // namespace collatz_conjecture
