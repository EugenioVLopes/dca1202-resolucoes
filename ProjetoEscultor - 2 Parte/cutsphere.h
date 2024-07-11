#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

/**
 * @brief A classe CutSphere representa a remoção de uma esfera em um Sculptor.
 */
class CutSphere : public FiguraGeometrica {
private:
  int xcenter, ycenter,
      zcenter; /// Coordenadas do centro da esfera no Sculptor.
  int radius;  /// Raio da esfera a ser removida.
public:
  /**
   * @brief Construtor padrão da classe CutSphere.
   */
  CutSphere();
  /**
   * @brief Destrutor da classe CutSphere.
   */
  virtual ~CutSphere();
  /**
   * @brief Método responsável por remover a esfera no Sculptor.
   * @param t Referência para um objeto Sculptor onde a esfera será removida.
   */
  void draw(Sculptor &t);
  /**
   * @brief Construtor parametrizado da classe CutSphere.
   * @param v Vetor contendo as informações da esfera a ser removida (xcenter,
   * ycenter, zcenter, radius).
   */
  CutSphere(std::vector<std::string> v);
};

#endif // CUTSPHERE_H