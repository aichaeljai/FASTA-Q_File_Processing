#ifndef __SEQUENCE_CLEANER_H__
#define __SEQUENCE_CLEANER_H__

#include "sequence_biologique.h"

/**
 * Classe dédiée au nettoyage des séquences biologiques.
 */
class SequenceCleaner {
public:
  /**
   * Nettoie une séquence biologique en supprimant les caractères invalides.
   *
   * \param sequence La séquence biologique à nettoyer.
   *
   * \return Une nouvelle séquence nettoyée.
   */
  static SequenceBiologique clean(const SequenceBiologique &sequence);

  /**
   * Filtre les séquences en fonction de leur qualité.
   *
   * \param sequence La séquence biologique à filtrer.
   * \param qualityThreshold Le seuil de qualité minimum.
   *
   * \return Une nouvelle séquence filtrée.
   */
  static SequenceBiologique filterByQuality(const SequenceBiologique &sequence, double qualityThreshold);
};

#endif
