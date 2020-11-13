#if !defined(SAY_H)
#define SAY_H

#include <map>
#include <stdexcept>
#include <string>
#include <type_traits>

namespace say {

using std::string;

constexpr auto max_number = 999'999'999'999ull;

std::map<unsigned long, string> const map{
    {0, "zero"},          {1, "one"},
    {2, "two"},           {3, "three"},
    {4, "four"},          {5, "five"},
    {6, "six"},           {7, "seven"},
    {8, "eight"},         {9, "nine"},
    {10, "ten"},          {11, "eleven"},
    {12, "twelve"},       {13, "thirteen"},
    {14, "fourteen"},     {15, "fifteen"},
    {16, "sixteen"},      {17, "seventeen"},
    {18, "eighteen"},     {19, "nineteen"},
    {20, "twenty"},       {30, "thirty"},
    {40, "forty"},        {50, "fifty"},
    {60, "sixty"},        {70, "seventy"},
    {80, "eighty"},       {90, "ninety"},
    {100, "hundred"},     {1000, "thousand"},
    {1000000, "million"}, {1'000'000'000, "billion"}};

template <typename T> string in_english(T number) {
  if (std::is_signed<T>::value)
    throw std::domain_error{"Signed Number."};
  else if (number > max_number)
    throw std::domain_error{"Number out of range."};

  if (number >= 1'000'000'000) {
    return in_english(number / 1'000'000'000) + ' ' + map.at(1'000'000'000) +
           (number % 1'000'000'000 != 0
                ? ' ' + in_english(number % 1'000'000'000)
                : "");
  } else if (number >= 1000000) {
    return in_english(number / 1000000) + ' ' + map.at(1000000) +
           (number % 1000000 != 0 ? ' ' + in_english(number % 1000000) : "");
  } else if (number >= 1000) {
    return in_english(number / 1000) + ' ' + map.at(1000) +
           (number % 1000 != 0 ? ' ' + in_english(number % 1000) : "");
  } else if (number >= 100) {
    return map.at(number / 100) + ' ' + map.at(100) +
           (number % 100 != 0 ? ' ' + in_english(number % 100) : "");
  } else if (number > 20) {
    return map.at((number / 10) * 10) + '-' + map.at(number % 10);
  } else {
    return map.at(number);
  }
}

} // namespace say

#endif // SAY_H
