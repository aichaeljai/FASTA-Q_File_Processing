#include "sequence_cleaner.h"

SequenceBiologique SequenceCleaner::clean(const SequenceBiologique &sequence) {
  std::string cleanedSequence;
  for (char c : sequence.getSequence()) {
    if (sequence.isValid(c)) {
      cleanedSequence += c;
    }
  }
  return SequenceBiologique(sequence.getDescription(), cleanedSequence, sequence.getQuality());
}

SequenceBiologique SequenceCleaner::filterByQuality(const SequenceBiologique &sequence, double qualityThreshold) {
  std::string filteredSequence;
  std::string filteredQuality;

  for (size_t i = 0; i < sequence.getSequence().length(); ++i) {
    if (sequence.getProbabilityOfError(i) <= qualityThreshold) {
      filteredSequence += sequence.getSequence()[i];
      filteredQuality += sequence.getQuality()[i];
    }
  }

  return SequenceBiologique(sequence.getDescription(), filteredSequence, filteredQuality);
}
