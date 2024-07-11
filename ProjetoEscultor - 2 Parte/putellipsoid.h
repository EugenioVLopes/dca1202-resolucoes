#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

/**
 * @brief A classe PutEllipsoid representa a criação de um elipsoide em um
 * Sculptor.
 */
class PutEllipsoid : public FiguraGeometrica {
private:
  int xcenter, ycenter,
      zcenter;             /// Coordenadas do centro do elipsoide no Sculptor.
  int raiox, raioy, raioz; /// Raios do elipsoide nos eixos x, y e z.
  float r, g, b, a;        /// Cores e transparência do elipsoide.
public:
  /**
   * @brief Construtor padrão da classe PutEllipsoid.
   */
  PutEllipsoid();
  /**
   * @brief Destrutor da classe PutEllipsoid.
   */
  virtual ~PutEllipsoid();
  /**
   * @brief Método responsável por desenhar o elipsoide no Sculptor.
   * @param t Referência para um objeto Sculptor onde o elipsoide será
   * desenhado.
   */
  void draw(Sculptor &t);
  /**
   * @brief Construtor parametrizado da classe PutEllipsoid.
   * @param v Vetor contendo as informações do elipsoide (xcenter, ycenter,
   * zcenter, raiox, raioy, raioz, r, g, b, a).
   */
  PutEllipsoid(std::vector<std::string> v);
};

#endif // PUTELLIPSOID_H