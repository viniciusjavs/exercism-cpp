#include "prime_factors.h"

namespace prime_factors {

std::vector<int> of(int number) {
  std::vector<int> result;
  for (int i = 2; number != 1;) {
    if (number % i == 0) {
      result.push_back(i);
      number /= i;
    } else {
      ++i;
    }
  }
  return result;
}

} // namespace prime_factors
