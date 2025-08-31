#include "read_mapper.h"

ReadMapper::ReadMapper(const std::string &genome, size_t k): _index(genome, k) {}

std::vector<size_t> ReadMapper::mapRead(const SequenceBiologique &read) const {
  std::vector<size_t> positions;
  std::string sequence = read.getSequence();
  for (size_t i = 0; i + _index.getKmerAt(0).length() <= sequence.length(); ++i) {
    std::string kmer = sequence.substr(i, _index.getKmerAt(0).length());
    if (_index.contains(kmer)) {
      auto pos = _index.getPositions(kmer);
      positions.insert(positions.end(), pos.begin(), pos.end());
    }
  }
  return positions;
}
