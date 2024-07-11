#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <string>
#include <vector>

/**
 * @brief A estrutura Voxel representa um elemento básico em um escultor 3D.
 */
struct Voxel {
  float r;   /// Componentes de cor Vermelho.
  float g;   /// Componentes de cor Verde.
  float b;   /// Componentes de cor Azul.
  float a;   /// Transparência.
  bool show; /// Variável de apresentação.
};

/**
 * @brief A classe Sculptor representa um escultor 3D.
 */
class Sculptor {

private:
  Voxel ***v;       /// Matriz 3D de voxels.
  int nx, ny, nz;   /// Dimensões do escultor.
  float r, g, b, a; /// Cor atual para desenho.
public:
  int Nvertices = 0;
  int Nfaces = 0;
  /**
   * @brief Construtor da classe Sculptor.
   * @param vt Vetor contendo informações de inicialização (dimensões nx, ny,
   * nz).
   */
  Sculptor(std::vector<std::string> vt);
  /**
   * @brief Destrutor da classe Sculptor.
   */
  virtual ~Sculptor();
  /**
   * @brief Define a cor atual para desenho.
   * @param r Valor do componente vermelho (0-1).
   * @param g Valor do componente verde (0-1).
   * @param b Valor do componente azul (0-1).
   * @param a Valor da transparência (0-1).
   */
  void setColor(float r, float g, float b, float a);
  /**
   * @brief Escreve o escultor em formato OFF no arquivo especificado.
   * @param filename Nome do arquivo OFF.
   */
  void writeOFF(const char *filename);
  /**
   * @brief Obtém a dimensão em x do escultor.
   * @return Dimensão em x.
   */
  int getNx() const;
  /**
   * @brief Obtém a dimensão em y do escultor.
   * @return Dimensão em y.
   */
  int getNy() const;
  /**
   * @brief Obtém a dimensão em z do escultor.
   * @return Dimensão em z.
   */
  int getNz() const;
  /**
   * @brief Ativa o voxel nas coordenadas especificadas.
   * @param x Coordenada x.
   * @param y Coordenada y.
   * @param z Coordenada z.
   */
  void putVoxel(int x, int y, int z);
  /**
   * @brief Desativa o voxel nas coordenadas especificadas.
   * @param x Coordenada x.
   * @param y Coordenada y.
   * @param z Coordenada z.
   */
  void cutVoxel(int x, int y, int z);
};

#endif // SCULPTOR_H