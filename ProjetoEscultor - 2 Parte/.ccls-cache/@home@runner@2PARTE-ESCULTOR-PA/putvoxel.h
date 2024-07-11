#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"
#include <string>
#include <vector>

/**
 * @brief A classe PutVoxel representa um voxel ativo em um Sculptor.
 */
class PutVoxel : public FiguraGeometrica {
private:
  int x, y, z;      /// Coordenadas do voxel no Sculptor.
  float r, g, b, a; /// Cores e transparência do voxel.
public:
  /**
   * @brief Construtor padrão da classe PutVoxel.
   */
  PutVoxel();
  /**
   * @brief Destrutor da classe PutVoxel.
   */
  virtual ~PutVoxel();
  /**
   * @brief Método responsável por desenhar o voxel no Sculptor.
   * @param t Referência para um objeto Sculptor onde o voxel será desenhado.
   */
  void draw(Sculptor &t);
  /**
   * @brief Construtor parametrizado da classe PutVoxel.
   * @param v Vetor contendo as informações do voxel (x, y, z, r, g, b, a).
   */
  PutVoxel(std::vector<std::string> v);
};

#endif // PUTVOXEL_H