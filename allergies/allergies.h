#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::string_view;

namespace allergies {

class allergy_test {
  static const std::unordered_map<string_view, unsigned short> allergy;
  unsigned short score_;

public:
  allergy_test(unsigned short score) : score_{score} {};
  bool is_allergic_to(string_view sv) const;
  std::unordered_set<string> get_allergies() const;
};

} // namespace allergies

#endif // ALLERGIES_H
