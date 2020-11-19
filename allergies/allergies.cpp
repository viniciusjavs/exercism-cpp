#include "allergies.h"

#include <algorithm>

namespace allergies {

const std::unordered_map<string_view, unsigned short> allergy_test::allergy{
    {"eggs", 1},      {"peanuts", 2},    {"shellfish", 4}, {"strawberries", 8},
    {"tomatoes", 16}, {"chocolate", 32}, {"pollen", 64},   {"cats", 128}};

bool allergy_test::is_allergic_to(string_view sv) const {
  return allergy.contains(sv) and allergy.at(sv) & score_;
}

std::unordered_set<string> allergy_test::get_allergies() const {
  std::unordered_set<string> result;
  std::for_each(cbegin(allergy), cend(allergy),
                [this, &result](const auto &pair) {
                  if (pair.second & score_)
                    result.insert(string{pair.first});
                });
  return result;
}

} // namespace allergies
