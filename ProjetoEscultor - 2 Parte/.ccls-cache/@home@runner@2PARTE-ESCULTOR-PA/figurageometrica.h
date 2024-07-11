#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"
/**
 * @brief A classe FiguraGeometrica representa uma figura geométrica genérica.
 */
class FiguraGeometrica {
public:
  /**
   * @brief Construtor padrão da classe FiguraGeometrica.
   */
  FiguraGeometrica();
  /**
   * @brief Destrutor virtual da classe FiguraGeometrica.
   */
  virtual ~FiguraGeometrica();
  /**
   * @brief Método virtual puro para desenhar a figura geométrica em um objeto
   * Sculptor.
   * @param t Referência para um objeto Sculptor onde a figura será desenhada.
   */
  virtual void draw(Sculptor &t) = 0;
};

#endif // FIGURAGEOMETRICA_H