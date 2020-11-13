#include "sieve.h"

#include <numeric>

namespace sieve {

std::vector<int> primes(int limit) {
  if (limit < 2)
    return {};
  std::vector<int> result(limit - 1);
  std::iota(begin(result), end(result), 2);

  for (int i = 2; i < limit; ++i) {
    for (int j = i + i; j <= limit; j += i)
      std::erase(result, j);
  }
  return result;
}
} // namespace sieve
