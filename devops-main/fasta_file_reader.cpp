#include "fasta_file_reader.h"

FastaFileReader::FastaFileReader(const std::string &filename) : FileReader(filename) {
  open(filename);
}

bool FastaFileReader::_isSequenceStart(char c) const {
    return c == '>';
}

bool FastaFileReader::_isSequenceEnd(char c) const {
    return c == '>' || c == '\0';
}

void FastaFileReader::_parseQuality() {
    // Le format FASTA ne contient pas de séquences de qualité,
    // cette méthode reste donc vide.
}

FileReader::Format FastaFileReader::getFormat() const {
    return FileReader::FASTA;
}