#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <string>
#include <vector>

/**
 * @struct Voxel
 * @brief Representa um voxel, que é um elemento básico para a construção de esculturas.
 */
struct Voxel
{
  float r;   /**< Componente vermelho da cor do voxel. */
  float g;   /**< Componente verde da cor do voxel. */
  float b;   /**< Componente azul da cor do voxel. */
  float a;   /**< Transparência do voxel. */
  bool show; /**< Indica se o voxel deve ser exibido ou não. */
};

/**
 * @brief A classe Sculptor representa um escultor 3D.
 *
 * O escultor é representado por uma matriz tridimensional de voxels,
 * onde cada voxel possui uma cor RGBA.
 *
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
   * @param vetor Vetor contendo informações (dimensões nx, ny, nz).
   */
  Sculptor(std::vector<std::string> vetor);
/**
 * @brief Destrutor da classe Sculptor.
 *
 * Libera a memória alocada para a matriz tridimensional que representa o escultor.
 *
 * @see Sculptor
 */
  virtual ~Sculptor();
/**
 * @brief Define a cor atual de desenho.
 *
 * @param r Valor do componente vermelho da cor (entre 0 e 1).
 * @param g Valor do componente verde da cor (entre 0 e 1).
 * @param b Valor do componente azul da cor (entre 0 e 1).
 * @param a Valor da transparência da cor (entre 0 e 1).
 */
  void setColor(float r, float g, float b, float a);
/**
 * @brief Salva a escultura em um arquivo OFF.
 *
 * @param filename O nome do arquivo a ser criado.
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
   * @brief Torna visivel o voxel nas coordenadas especificadas.
 *
 * @param x A coordenada x do voxel.
 * @param y A coordenada y do voxel.
 * @param z A coordenada z do voxel.
 */
  void putVoxel(int x, int y, int z);
/**
 * @brief Método responsável por desativar um voxel na posição x,y e z.
 *
 * @param x A coordenada x do voxel a ser removido.
 * @param y A coordenada y do voxel a ser removido.
 * @param z A coordenada z do voxel a ser removido.
 */
  void cutVoxel(int x, int y, int z);
};

#endif // SCULPTOR_H