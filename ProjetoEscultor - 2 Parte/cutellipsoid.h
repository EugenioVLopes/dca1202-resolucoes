#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

/**
 * @brief A classe CutEllipsoid institui a remoção de um elipsoide em um
 * Sculptor.
 */
class CutEllipsoid : public FiguraGeometrica {
private:
  int xcenter, ycenter,
      zcenter;             /// Coordenadas do centro do elipsoide no Sculptor.
  int raiox, raioy, raioz; /// Raios do elipsoide nos eixos x, y e z.
public:
  /**
   * @brief Construtor padrão da classe CutEllipsoid.
   */
  CutEllipsoid();
  /**
   * @brief Destrutor da classe CutEllipsoid.
   */
  virtual ~CutEllipsoid();
  /**
   * @brief Método responsável por remover o elipsoide no Sculptor.
   * @param t Referência para um objeto Sculptor onde o elipsoide será removido.
   */
  void draw(Sculptor &t);
  /**
   * @brief Construtor parametrizado da classe CutEllipsoid.
   * @param v Vetor contendo as informações do elipsoide a ser removido
   * (xcenter, ycenter, zcenter, raiox, raioy, raioz).
   */
  CutEllipsoid(std::vector<std::string> v);
};

#endif // CUTELLIPSOID_H