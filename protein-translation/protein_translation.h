#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <string>
#include <vector>

namespace protein_translation {

using std::string;
using std::string_view;
using std::vector;

vector<string> proteins(string_view strand);

} // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
