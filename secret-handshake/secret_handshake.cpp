#include "secret_handshake.h"

#include <algorithm>
#include <map>

namespace secret_handshake {

using std::string_view;

const std::map<unsigned short, string_view> handshake{
    {1, "wink"},
    {0b10, "double blink"},
    {0b100, "close your eyes"},
    {0b1000, "jump"}};

/* Reverse the order of the operations in the secret handshake. */
const unsigned short reverse{0b10000};

vector<string> commands(unsigned short secret) {
  vector<string> result;
  std::for_each(cbegin(handshake), cend(handshake),
                [secret, &result](const auto &pair) {
                  if (secret & pair.first)
                    result.emplace_back(pair.second);
                });
  if (secret & reverse)
    std::reverse(begin(result), end(result));
  return result;
}

} // namespace secret_handshake
