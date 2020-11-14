#include "queen_attack.h"

namespace queen_attack {

chess_board::chess_board(pair_t white, pair_t black)
    : white_{white}, black_{black} {
  if (white == black)
    throw std::domain_error("Queen positions must be distinct");
}

chess_board::operator string() const {
  string board;
  board.reserve((size * 2) * size);
  for (int row : iota(0, size)) {
    for (int column : iota(0, size))
      if (auto pair = std::make_pair(row, column); pair == white_)
        board.append("W ");
      else if (pair == black_)
        board.append("B ");
      else
        board.append("_ ");
    board.pop_back();
    board.push_back('\n');
  }
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
