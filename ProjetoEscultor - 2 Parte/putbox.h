#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"
#include "sculptor.h"
#include <string>
#include <vector>

/**
 * @brief A classe PutBox constitui a criação de uma caixa/box.
 */
class PutBox : public FiguraGeometrica {
private:
  int x, x1, y, y1, z, z1; /// Coordenadas da caixa no Sculptor.
  float r, g, b, a;        /// Cores e transparência da caixa.
public:
  /**
   * @brief Construtor padrão da classe PutBox.
   */
  PutBox();
  /**
   * @brief Destrutor da classe PutBox.
   */
  virtual ~PutBox();
  /**
   * @brief Método responsável por desenhar a caixa no Sculptor.
   * @param t Referência para um objeto Sculptor onde a caixa será desenhada.
   */
  void draw(Sculptor &t);
  /**
   * @brief Construtor parametrizado da classe PutBox.
   * @param v Vetor contendo as informações da caixa (x, x1, y, y1, z, z1, r, g,
   * b, a).
   */
  PutBox(std::vector<std::string> v);
};

#endif // PUTBOX_H