#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <cmath>
#include <stdexcept>
#include <utility>

namespace queen_attack {

using pair_t = std::pair<int, int>;
using std::string;

class chess_board {
  static constexpr auto size = 8;
  pair_t white_;
  pair_t black_;

public:
  chess_board(pair_t white = {0, 3}, pair_t black = {7, 3});

  pair_t white() const { return white_; }
  pair_t black() const { return black_; }

  explicit operator string() const;

  bool can_attack() const;
};

} // namespace queen_attack

#endif // QUEEN_ATTACK_H
