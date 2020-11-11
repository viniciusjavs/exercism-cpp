#include "difference_of_squares.h"

#include <cmath>
#include <numeric>
#include <vector>

namespace difference_of_squares {

int square_of_sum(int n) {
  std::vector<int> ints(n);
  std::iota(begin(ints), end(ints), 1);
  return std::pow(std::accumulate(cbegin(ints), cend(ints), 0), 2);
}

int sum_of_squares(int n) {
  std::vector<int> ints(n);
  std::iota(begin(ints), end(ints), 1);
  return std::inner_product(cbegin(ints), cend(ints), cbegin(ints), 0);
}

int difference(int n) { return square_of_sum(n) - sum_of_squares(n); }

} // namespace difference_of_squares
