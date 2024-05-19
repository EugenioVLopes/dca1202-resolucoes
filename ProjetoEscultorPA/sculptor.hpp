#ifndef SCULPTOR_HP
#define SCULPTOR_HP

/**
 * @file sculptor.hpp
 * @brief Definição da estrutura Voxel e suas propriedades.
 */

/**
 * @struct Voxel
 * @brief Representa um voxel, que é um elemento básico para a construção de esculturas.
 */
struct Voxel
{
  float r;   /**< Componente vermelho da cor do voxel (0 a 1). */
  float g;   /**< Componente verde da cor do voxel (0 a 1). */
  float b;   /**< Componente azul da cor do voxel (0 a 1). */
  float a;   /**< Transparência do voxel (0 a 1). */
  bool show; /**< Indica se o voxel deve ser exibido ou não. */
};

/**
 * @file sculptor.hpp
 * @brief Definição da classe Sculptor
 */

/**
 * @brief A classe Sculptor representa um escultor 3D.
 *
 * O escultor é representado por uma matriz tridimensional de voxels,
 * onde cada voxel possui uma cor RGBA.
 *
 * É possível realizar operações de desenho e corte na escultura, como
 * colocar um voxel, cortar um voxel, colocar uma caixa, cortar uma caixa,
 * colocar uma esfera, cortar uma esfera, colocar uma elipsoide e cortar uma elipsoide.
 *
 * Também é possível salvar a escultura em um arquivo OFF.
 */
class Sculptor
{
private:
  Voxel ***v;       // 3D matrix
  int nx, ny, nz;   // Dimensions
  float r, g, b, a; // Current drawing color
public:
  Sculptor(int _nx, int _ny, int _nz);                                              // Construtor
  ~Sculptor();                                                                      // Destrutor
  void setColor(float r, float g, float b, float a);                                // Método que defini a cor
  void putVoxel(int x, int y, int z);                                               // Método que 'coloca' um voxel
  void cutVoxel(int x, int y, int z);                                               // Método que 'corta' um voxel
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);                      // Método que 'coloca' uma caixa/cubo
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);                      // Método que 'corta' uma caixa/cubo
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);                // Método que 'coloca' uma esfera
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);                // Método que 'corta' uma esfera
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Método que 'coloca' uma elipsoide
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Método que 'corta' uma elipsoide
  void writeOFF(const char *filename);                                              // Método que salva a escultura em um arquivo OFF
};

#endif