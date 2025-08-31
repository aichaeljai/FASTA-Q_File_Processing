#ifndef __KMER_INDEX_H__
#define __KMER_INDEX_H__

#include <string>
#include <unordered_map>
#include <vector>

/**
 * Classe pour indexer des k-mers dans un texte.
 */
class KmerIndex {
private:
  size_t _k;
  std::unordered_map<std::string, std::vector<size_t>> _index;

public:
  /**
   * Construit un index de k-mers à partir d'un texte.
   *
   * \param text Le texte à indexer.
   * \param k La longueur des k-mers.
   */
  KmerIndex(const std::string &text, size_t k);

  /**
   * Vérifie si un k-mer est présent dans le texte.
   *
   * \param kmer Le k-mer à rechercher.
   *
   * \return Vrai si le k-mer est présent, faux sinon.
   */
  bool contains(const std::string &kmer) const;

  /**
   * Renvoie les positions d'un k-mer dans le texte.
   *
   * \param kmer Le k-mer à rechercher.
   *
   * \return Un vecteur des positions du k-mer.
   */
  std::vector<size_t> getPositions(const std::string &kmer) const;

  /**
   * Renvoie le k-mer à une position donnée.
   *
   * \param position La position dans le texte.
   *
   * \return Le k-mer à la position donnée.
   */
  std::string getKmerAt(size_t position) const;
};

#endif
