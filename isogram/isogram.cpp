#include "isogram.h"

#include <algorithm>
#include <cctype>

namespace isogram {

bool is_isogram(string str) {
  std::erase_if(str, [](unsigned char c) { return !std::isalpha(c); });
  std::transform(cbegin(str), cend(str), begin(str),
                 [](unsigned char c) { return std::tolower(c); });
  std::sort(begin(str), end(str));
  return std::adjacent_find(cbegin(str), cend(str)) == cend(str);
}

} // namespace isogram
