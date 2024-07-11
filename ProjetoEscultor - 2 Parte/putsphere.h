#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

/**
 * @brief A classe PutSphere constitui a criação de uma esfera.
 */
class PutSphere : public FiguraGeometrica {
private:
  int xcenter, ycenter,
      zcenter;      /// Coordenadas do centro da esfera no Sculptor.
  int radius;       ///< Raio da esfera.
  float r, g, b, a; ///< Cores e transparência da esfera.
public:
  /**
   * @brief Construtor padrão da classe PutSphere.
   */
  PutSphere();
  /**
   * @brief Destrutor da classe PutSphere.
   */
  virtual ~PutSphere();
  /**
   * @brief Método responsável por desenhar a esfera no Sculptor.
   * @param t Referência para um objeto Sculptor onde a esfera será desenhada.
   */
  void draw(Sculptor &t);
  /**
   * @brief Construtor parametrizado da classe PutSphere.
   * @param v Vetor contendo as informações da esfera (xcenter, ycenter,
   * zcenter, radius, r, g, b, a).
   */
  PutSphere(std::vector<std::string> v);
};

#endif // PUTSPHERE_H