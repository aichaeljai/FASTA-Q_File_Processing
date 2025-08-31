#include "fastq_file_reader.h"

FastqFileReader::FastqFileReader(const std::string &filename): FileReader() {
  if (!filename.empty()) {
    open(filename);
  }
}

bool FastqFileReader::_isSequenceStart(char c) const {
  return (c == '@');
}

bool FastqFileReader::_isSequenceEnd(char c) const {
  return (c == '+');
}

void FastqFileReader::_parseQuality() {
  // Implémentation pour lire la séquence qualité.
  std::string quality;
  while (_stream.good()) {
    char c = _stream.get();
    if (_stream.eof() || c == '\n') {
      break;
    }
    quality += c;
  }
  // Stocker ou traiter la séquence qualité si nécessaire.
}

FileReader::Format FastqFileReader::getFormat() const {
  return FASTQ;
}
