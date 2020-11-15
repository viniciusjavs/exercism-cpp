#include "gigasecond.h"

namespace gigasecond {

constexpr unsigned long long operator""_Gs(unsigned long long number) {
  return number * 1e9;
}

ptime advance(ptime time) { return time + seconds{1_Gs}; }

} // namespace gigasecond
