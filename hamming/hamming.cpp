#include "hamming.h"

namespace hamming {

int compute(string const &first, string const &second) {
  auto len = first.length();
  if (len != second.length())
    throw std::domain_error{"sequences differ in length"};

  int result{0};

  for (std::size_t i{0}; i <= len; ++i)
    if (first[i] != second[i])
      ++result;

  return result;
}

} // namespace hamming
