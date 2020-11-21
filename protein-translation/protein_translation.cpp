#include "protein_translation.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>

namespace protein_translation {

namespace {
constexpr string_view phenylalanine{"Phenylalanine"};
constexpr string_view leucine{"Leucine"};
constexpr string_view serine{"Serine"};
constexpr string_view tyrosine{"Tyrosine"};
constexpr string_view cysteine{"Cysteine"};
}

const std::unordered_map<string_view, string_view> amino_acid{
    {"AUG", "Methionine"}, {"UUU", phenylalanine}, {"UUC", phenylalanine},
    {"UUA", leucine},      {"UUG", leucine},       {"UCU", serine},
    {"UCC", serine},       {"UCA", serine},        {"UCG", serine},
    {"UAU", tyrosine},     {"UAC", tyrosine},      {"UGU", cysteine},
    {"UGC", cysteine},     {"UGG", "Tryptophan"}};

const std::unordered_set<string_view> stop{"UAA", "UAG", "UGA"};

vector<string> proteins(string_view strand) {
  vector<string> result;
  for (std::size_t count{3}, pos{}; pos < strand.size(); pos += count) {
    auto codon = strand.substr(pos, count);
    if (stop.contains(codon))
      break;
    else
      result.emplace_back(amino_acid.at(codon));
  }
  return result;
}

} // namespace protein_translation
