#include "robot_name.h"
#include <random>

namespace robot_name {

std::random_device rand_dev;
std::default_random_engine rand_engine(rand_dev());

string robot::random_name() {
  string name;
  name.reserve(size);
  name.push_back(random_upper_letter());
  name.push_back(random_upper_letter());
  for (int i = 0; i < 3; ++i)
    name.push_back(random_digit());
  return name;
}

char robot::random_upper_letter() {
  std::uniform_int_distribution<short> uniform_dist{'A', 'Z'};
  return uniform_dist(rand_engine);
}

char robot::random_digit() {
  std::uniform_int_distribution<short> uniform_dist{'0', '9'};
  return uniform_dist(rand_engine);
}

} // namespace robot_name
