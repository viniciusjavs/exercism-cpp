#include "nth_prime.h"
#include <algorithm>
#include <ranges>
#include <stdexcept>

namespace nth_prime {

using namespace std::views;

auto divisible = [](auto dividend) {
  return [dividend](auto divisor) { return dividend % divisor == 0; };
};

auto prime = [](auto number) {
  return std::ranges::none_of(iota(2, number), divisible(number));
};

int nth(int pos) {
  if (pos <= 0)
    throw std::domain_error{"\'N\' must be positive."};
  auto r = iota(2) | filter(prime) | take(pos) | reverse;
  return *std::ranges::begin(r);
}

} // namespace nth_prime
