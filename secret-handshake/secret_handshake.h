#if !defined(SECRET_HANDSHAKE_H)
#define SECRET_HANDSHAKE_H

#include <string>
#include <vector>

namespace secret_handshake {

using std::string;
using std::vector;

vector<string> commands(unsigned short secret);

} // namespace secret_handshake

#endif // SECRET_HANDSHAKE_H
