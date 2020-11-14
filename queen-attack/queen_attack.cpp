#include "queen_attack.h"

namespace queen_attack {

chess_board::chess_board(pair_t white, pair_t black)
    : white_{white}, black_{black} {
  if (white == black)
    throw std::domain_error("Queen positions must be distinct");
}

chess_board::operator string() const {
  string board{"_ _ _ _ _ _ _ _\n"
               "_ _ _ _ _ _ _ _\n"
               "_ _ _ _ _ _ _ _\n"
               "_ _ _ _ _ _ _ _\n"
               "_ _ _ _ _ _ _ _\n"
               "_ _ _ _ _ _ _ _\n"
               "_ _ _ _ _ _ _ _\n"
               "_ _ _ _ _ _ _ _\n"};

  board[white_.first * (size * 2) + white_.second * 2] = 'W';
  board[black_.first * (size * 2) + black_.second * 2] = 'B';

  return board;
}

bool chess_board::can_attack() const {
  if ((white_.first == black_.first) || (white_.second == black_.second))
    return true;
  if (std::abs(white_.second - black_.second) ==
      std::abs(white_.first - black_.first))
    return true;
  return false;
}

} // namespace queen_attack
