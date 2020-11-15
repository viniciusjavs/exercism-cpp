#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <string>

namespace robot_name {

using std::string;

class robot {
  static constexpr int size = 5;
  string name_;
  string random_name();
  char random_upper_letter();
  char random_digit();

public:
  robot() : name_{random_name()} {}
  const string &name() const { return name_; }
  void reset() { name_ = random_name(); }
};

} // namespace robot_name

#endif // ROBOT_NAME_H
