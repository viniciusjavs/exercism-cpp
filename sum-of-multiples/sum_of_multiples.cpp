#include "sum_of_multiples.h"

#include <numeric>
#include <set>

namespace sum_of_multiples {

int to(std::initializer_list<int> numbers, int limit) {
  std::set<int> multiples;
  for (int number : numbers)
    for (int n{number}; n < limit; n += number)
      multiples.insert(n);
  return std::reduce(cbegin(multiples), cend(multiples));
}

} // namespace sum_of_multiples
