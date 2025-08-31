#ifndef __READ_MAPPER_H__
#define __READ_MAPPER_H__

#include "kmer_index.h"
#include "sequence_biologique.h"
#include <vector>

/**
 * Classe pour mapper des reads sur un génome de référence.
 */
class ReadMapper {
private:
  KmerIndex _index;

public:
  /**
   * Construit un mapper à partir d'un génome de référence.
   *
   * \param genome Le génome de référence.
   * \param k La longueur des k-mers.
   */
  ReadMapper(const std::string &genome, size_t k);

  /**
   * Mappe un read sur le génome.
   *
   * \param read Le read à mapper.
   *
   * \return Les positions où le read est mappé.
   */
  std::vector<size_t> mapRead(const SequenceBiologique &read) const;
};

#endif
