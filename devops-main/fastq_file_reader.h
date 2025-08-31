/*****************************************************************************
* Copyright 2024-2025 -- Alban Mancheron                                     *
*                                                                            *
* Author: Alban Mancheron <alban.mancheron@umontpellier.fr>                  *
*                                                                            *
******************************************************************************
*                                                                            *
* Ce logiciel est un programme informatique servant à illustrer les concepts *
* de DevOps vus dans le cadre de l'UE HAU803I.                               *
*                                                                            *
* Ce logiciel est régi par la licence CeCILL soumise au droit français et    *
* respectant les principes de diffusion des logiciels libres. Vous pouvez    *
* utiliser, modifier et/ou redistribuer ce programme sous les conditions     *
* de la licence CeCILL telle que diffusée par le CEA, le CNRS et l'INRIA     *
* sur le site "http://www.cecill.info".                                      *
*                                                                            *
* En contrepartie de l'accessibilité au code source et des droits de copie,  *
* de modification et de redistribution accordés par cette licence, il n'est  *
* offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,  *
* seule une responsabilité restreinte pèse sur l'auteur du programme,  le    *
* titulaire des droits patrimoniaux et les concédants successifs.            *
*                                                                            *
* A cet égard  l'attention de l'utilisateur est attirée sur les risques      *
* associés au chargement,  à l'utilisation,  à la modification et/ou au      *
* développement et à la reproduction du logiciel par l'utilisateur étant     *
* donné sa spécificité de logiciel libre, qui peut le rendre complexe à      *
* manipuler et qui le réserve donc à des développeurs et des professionnels  *
* avertis possédant  des  connaissances  informatiques approfondies.  Les    *
* utilisateurs sont donc invités à charger  et  tester  l'adéquation  du     *
* logiciel à leurs besoins dans des conditions permettant d'assurer la       *
* sécurité de leurs systèmes et ou de leurs données et, plus généralement,   *
* à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.         *
*                                                                            *
* Le fait que vous puissiez accéder à cet en-tête signifie que vous avez     *
* pris connaissance de la licence CeCILL, et que vous en avez accepté les    *
* termes.                                                                    *
*                                                                            *
*****************************************************************************/

#ifndef __FASTQ_FILE_READER_H__
#define __FASTQ_FILE_READER_H__

#include "file_reader.h"

/**
 * Classe dédiée à la lecture de fichiers au format Fastq.
 */
class FastqFileReader: public FileReader {

protected:

  /**
   * Renvoie vrai si le caractère passé en paramètre est un caractère
   * de début de nouvelle séquence (donc '@').
   *
   * \param c Le caractère à tester.
   *
   * \return Retourne vrai si le caractère correspond au caractère de
   * début de nouvelle séquence.
   */
  virtual bool _isSequenceStart(char c) const;

  /**
   * Renvoie vrai si le caractère passé en paramètre est un caractère
   * marquant la fin de la séquence courante donc '+' (c'est la cas si
   * on est à la fin du fichier).
   *
   * \param c Le caractère à tester.
   *
   * \return Retourne vrai si le caractère correspond au caractère de
   * fin de nouvelle séquence, donc un début de nouvelle séquence.
   */
  virtual bool _isSequenceEnd(char c) const;

  /**
   * Lit la séquence qualité.
   */
  virtual void _parseQuality();

public:

  /**
   * Construit un lecteur de fichier contenant des séquences
   * biologiques au format fastq.
   *
   * \param filename Le nom du fichier à analyser (s'il existe).
   */
  FastqFileReader(const std::string &filename = "");

  /*
   * Renvoie le format du fichier en cours de lecture.
   */
  virtual Format getFormat() const;

};

#endif

// Local Variables:
// mode: c++
// End:
