#include "prime_factors.h"

namespace prime_factors {

vector<int> of(int number) {
  vector<int> result;
  int factor = 2;
  while (number != 1) {
    if (number % factor == 0) {
      result.emplace_back(factor);
      number /= factor;
    } else {
      ++factor;
    }
  }
  return result;
}

} // namespace prime_factors
