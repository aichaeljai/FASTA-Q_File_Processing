#include "kmer_index.h"

KmerIndex::KmerIndex(const std::string &text, size_t k): _k(k) {
  for (size_t i = 0; i + k <= text.length(); ++i) {
    std::string kmer = text.substr(i, k);
    _index[kmer].push_back(i);
  }
}

bool KmerIndex::contains(const std::string &kmer) const {
  return _index.find(kmer) != _index.end();
}

std::vector<size_t> KmerIndex::getPositions(const std::string &kmer) const {
  auto it = _index.find(kmer);
  return it != _index.end() ? it->second : std::vector<size_t>();
}

std::string KmerIndex::getKmerAt(size_t position) const {
  auto it = _index.begin();
  for (; it != _index.end(); ++it) {
    for (size_t pos : it->second) {
      if (pos == position) {
        return it->first;
      }
    }
  }
  return "";
}
