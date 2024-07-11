#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include <string>
#include <vector>
/**
 * @brief A classe CutVoxel institui a remoção de um voxel em um Sculptor.
 */
class CutVoxel : public FiguraGeometrica {
private:
  int x, y, z; /// Coordenadas do voxel a ser removido no Sculptor.
public:
  /**
   * @brief Construtor padrão da classe CutVoxel.
   */
  CutVoxel();
  /**
   * @brief Destrutor da classe CutVoxel.
   */
  virtual ~CutVoxel();
  /**
   * @brief Método responsável por remover o voxel no Sculptor.
   * @param t Referência para um objeto Sculptor onde o voxel será removido.
   */
  void draw(Sculptor &t);
  /**
   * @brief Construtor parametrizado da classe CutVoxel.
   * @param v Vetor contendo as informações do voxel a ser removido (x, y, z).
   */
  CutVoxel(std::vector<std::string> v);
};

#endif // CUTVOXEL_H