#include "sculptor.hpp"
#include <cmath>
#include <fstream>
#include <iostream>

/**
 * @brief Construtor da classe Sculptor.
 *
 * @param _nx Tamanho da dimensão x do escultor.
 * @param _ny Tamanho da dimensão y do escultor.
 * @param _nz Tamanho da dimensão z do escultor.
 */
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
  // Atribuição os valores de nx, ny e nz para o objeto Sculptor
  nx = _nx;
  ny = _ny;
  nz = _nz;

  v = new Voxel **[nx];              // Aloca memória para o array de ponteiros de ponteiros
  v[0] = new Voxel *[nx * ny];       // Aloca memória para o array de ponteiros
  v[0][0] = new Voxel[nx * ny * nz]; // Aloca memória

  // Verificando se a memória foi alocada corretamente
  if (v == nullptr || v[0] == nullptr || v[0][0] == nullptr)
  {
    printf("Memória insuficiente\n");
    exit(0);
  }

  // Laço de ajuste de posições de memória no array de v
  for (int i = 1; i < nx; i++)
  {
    v[i] = v[0] + i * ny;
  }
  for (int i = 1; i < nx * ny; i++)
  {
    v[0][i] = v[0][0] + i * nz;
  }
  std ::cout << "Objeto 3D criado: " << nx << " x " << ny << " x " << nz
             << std ::endl;
}

/**
 * @brief Destrutor da classe Sculptor.
 *
 * Libera a memória alocada para a matriz tridimensional que representa o escultor.
 *
 * @see Sculptor
 */
Sculptor::~Sculptor()
{
  // Implementação do destrutor liberando as memórias alocadas
  delete[] v[0][0];
  delete[] v[0];
  delete[] v;
}

/**
 * @brief Define a cor atual do escultor.
 *
 * @param r Valor do componente vermelho da cor (entre 0 e 1).
 * @param g Valor do componente verde da cor (entre 0 e 1).
 * @param b Valor do componente azul da cor (entre 0 e 1).
 * @param a Valor da transparência da cor (entre 0 e 1).
 */
void Sculptor::setColor(float r, float g, float b, float a)
{
  // Verifica se o valor de r está no intervalo correto (entre 0 e 1)
  if (r >= 0 && r <= 1)
  {
    // Atribui o valor de r ao atributo r da classe
    this->r = r;
  }
  // Verifica se o valor de g está no intervalo correto (entre 0 e 1)
  if (g >= 0 && g <= 1)
  {
    // Atribui o valor de g ao atributo g da classe
    this->g = g;
  }
  // Verifica se o valor de b está no intervalo correto (entre 0 e 1)
  if (b >= 0 && b <= 1)
  {
    // Atribui o valor de b ao atributo b da classe
    this->b = b;
  }
  // Verifica se o valor de alpha está no intervalo correto (entre 0 e 1)
  if (a >= 0 && a <= 1)
  {
    // Atribui o valor de alpha ao atributo a da classe
    this->a = a;
  }

  std::cout << "Cor definida: " << r << " " << g << " " << b << " " << a
            << std::endl;
}

/**
 * @brief Define um voxel na posição (x, y, z) como visível e define sua cor e transparência.
 *
 * @param x A coordenada x do voxel.
 * @param y A coordenada y do voxel.
 * @param z A coordenada z do voxel.
 */
void Sculptor::putVoxel(int x, int y, int z)
{

  // Define o voxel na posição (x, y, z) como visível
  v[x][y][z].show = true;

  // Define a cor e transparência do voxel na posição (x, y, z)
  v[x][y][z].r = r;
  v[x][y][z].g = g;
  v[x][y][z].b = b;
  v[x][y][z].a = a;
}

/**
 * @brief Método responsável por remover um voxel da matriz 3D.
 *
 * @param x A coordenada x do voxel a ser removido.
 * @param y A coordenada y do voxel a ser removido.
 * @param z A coordenada z do voxel a ser removido.
 */
void Sculptor::cutVoxel(int x, int y, int z)
{
  // Implementação do método cutVoxel => Remoção do Voxel
  v[x][y][z].show = false;
}

/**
 * @brief Adiciona uma caixa/cubo no escultor.
 *
 * @param x0 Coordenada x inicial da cubo.
 * @param x1 Coordenada x final da cubo.
 * @param y0 Coordenada y inicial da cubo.
 * @param y1 Coordenada y final da cubo.
 * @param z0 Coordenada z inicial da cubo.
 * @param z1 Coordenada z final da cubo.
 */
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
  // Implementação do método putBox => Adição de uma caixa/cubo
  for (int i = x0; i <= x1; i++)
  {
    for (int j = y0; j <= y1; j++)
    {
      for (int k = z0; k <= z1; k++)
      {
        putVoxel(i, j, k);
      }
    }
  }
}

/**
 * @brief Remove uma caixa/cubo do escultor.
 *
 * @param x0 Coordenada x do canto superior esquerdo da cubo.
 * @param x1 Coordenada x do canto inferior direito da cubo.
 * @param y0 Coordenada y do canto superior esquerdo da cubo.
 * @param y Coordenada y do canto inferior direito da cubo.
 * @param z0 Coordenada z do canto superior esquerdo da cubo.
 * @param z1 Coordenada z do canto inferior direito da cubo.
 */
void Sculptor::cutBox(int x0, int x1, int y0, int y, int z0, int z1)
{
  // Implementação do método cutBox => Remoção de uma caixa/cubo
  for (int i = x0; i <= x1; i++)
  {
    for (int j = y0; j <= y; j++)
    {
      for (int k = z0; k <= z1; k++)
      {
        cutVoxel(i, j, k);
      }
    }
  }
}

/**
 * @brief Adiciona uma esfera no escultor.
 *
 * @param xcenter Coordenada x do centro da esfera.
 * @param ycenter Coordenada y do centro da esfera.
 * @param zcenter Coordenada z do centro da esfera.
 * @param radius Raio da esfera.
 */
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
  // Implementação do método putSphere => Adição de uma esfera
  double equation;
  /*
   *(x-x0)^2 + (y - y0)^2 + (z - z0)^2 <= r^2
   */
  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      for (int k = 0; k < nz; k++)
      {
        equation =
            pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
        if (equation <= pow(radius, 2))
        {
          // Preenche apenas os pontos de dentro da esfera
          putVoxel(i, j, k);
        }
      }
    }
  }
}

/**
 * @brief Remove uma esfera do escultor.
 *
 * @param xcenter Coordenada x do centro da esfera.
 * @param ycenter Coordenada y do centro da esfera.
 * @param zcenter Coordenada z do centro da esfera.
 * @param radius Raio da esfera.
 */
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
  // Implementação do método cutSphere => Remoção de uma esfera
  double equation;

  for (int i = 0; i < nx; i++)
  {
    for (int j = 0; j < ny; j++)
    {
      for (int k = 0; k < nz; k++)
      {
        equation =
            pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
        if (equation <= pow(radius, 2))
        {

          // 'Corta' apenas os pontos de dentro da esfera
          cutVoxel(i, j, k);
        }
      }
    }
  }
}

/**
 * @brief Adiciona uma elipsoide no escultor.
 *
 * @param xcenter Coordenada x do centro da elipsoide.
 * @param ycenter Coordenada y do centro da elipsoide.
 * @param zcenter Coordenada z do centro da elipsoide.
 * @param rx Raio da elipsoide no eixo x.
 * @param ry Raio da elipsoide no eixo y.
 * @param rz Raio da elipsoide no eixo z.
 */
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz)
{
  // Implementação do método putEllipsoid => Adição de uma elipsoide
  double equation;

  /*
     *(x - a)^2 + (y - b)^2 + (z - c)^2 <= 1
      x=0 , y=0 , z=0
      a=xcenter; b=ycenter; c=zcenter
    */
  if (rx == 0)
  {
    for (int pz = 0; pz <= nz; pz++)
    {
      for (int py = 0; py <= ny; py++)
      {
        equation = (pow(py - ycenter, 2) / pow(ry, 2)) +
                   (pow(pz - zcenter, 2) / pow(rz, 2));
        if (equation <= 1)
        {
          putVoxel(xcenter, py, pz);
        }
      }
    }
  }
  else if (ry == 0)
  {
    for (int pz = 0; pz <= nz; pz++)
    {
      for (int px = 0; px <= nx; px++)
      {
        equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                   (pow(pz - zcenter, 2) / pow(rz, 2));
        if (equation <= 1)
        {
          putVoxel(px, ycenter, pz);
        }
      }
    }
  }
  else if (rz == 0)
  {
    for (int py = 0; py <= ny; py++)
    {
      for (int px = 0; px <= nx; px++)
      {
        equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                   (pow(py - ycenter, 2) / pow(ry, 2));
        if (equation <= 1)
        {
          putVoxel(px, py, zcenter);
        }
      }
    }
  }
  else
  {
    for (int pz = 0; pz <= nz; pz++)
    {
      for (int py = 0; py <= ny; py++)
      {
        for (int px = 0; px <= nx; px++)
        {
          equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                     (pow(py - ycenter, 2) / pow(ry, 2)) +
                     (pow(pz - zcenter, 2) / pow(rz, 2));
          if (equation <= 1)
          {
            putVoxel(px, py, pz);
          }
        }
      }
    }
  }
}

/**
 * @brief Remove uma elipsoide do escultor.
 *
 * @param xcenter Coordenada x do centro da elipsoide.
 * @param ycenter Coordenada y do centro da elipsoide.
 * @param zcenter Coordenada z do centro da elipsoide.
 * @param rx Raio da elipsoide no eixo x.
 * @param ry Raio da elipsoide no eixo y.
 * @param rz Raio da elipsoide no eixo z.
 */
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz)
{
  // Implementação do método cutEllipsoid => Remoção de uma elipsoide

  double equation;

  if (rx == 0)
  {
    for (int pz = 0; pz <= nz; pz++)
    {
      for (int py = 0; py <= ny; py++)
      {
        equation = (pow(py - ycenter, 2) / pow(ry, 2)) +
                   (pow(pz - zcenter, 2) / pow(rz, 2));
        if (equation <= 1)
        {
          cutVoxel(xcenter, py, pz);
        }
      }
    }
  }
  else if (ry == 0)
  {
    for (int pz = 0; pz <= nz; pz++)
    {
      for (int px = 0; px <= nx; px++)
      {
        equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                   (pow(pz - zcenter, 2) / pow(rz, 2));

        if (equation <= 1)
        {
          cutVoxel(px, ycenter, pz);
        }
      }
    }
  }
  else if (rz == 0)
  {
    for (int py = 0; py <= ny; py++)
    {
      for (int px = 0; px <= nx; px++)
      {
        equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                   (pow(py - ycenter, 2) / pow(ry, 2));

        if (equation <= 1)
        {
          cutVoxel(px, py, zcenter);
        }
      }
    }
  }
  else
  {
    for (int pz = 0; pz <= nz; pz++)
    {
      for (int py = 0; py <= ny; py++)
      {
        for (int px = 0; px <= nx; px++)
        {
          equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                     (pow(py - ycenter, 2) / pow(ry, 2)) +
                     (pow(pz - zcenter, 2) / pow(rz, 2));

          if (equation <= 1)
          {
            cutVoxel(px, py, pz);
          }
        }
      }
    }
  }
}

/**
 * @brief Salva a escultura em um arquivo OFF.
 *
 * @param filename O nome do arquivo a ser criado.
 */
void Sculptor::writeOFF(const char *filename)
{
  // Implementação do método writeOFF => Salva a escultura em um arquivo OFF

  /* FORMATO DO ARQUIVO OFF
        OFF
        NVertices  NFaces  NArestas
        x[0]  y[0]  z[0]
        ...
        x[NVertices-1]  y[NVertices-1]  z[NVertices-1]
        Nv v[0] v[1] ... v[Nv-1]  r g b a
        Nv v[0] v[1] ... v[Nv-1]  r g b a
        ...
        Nv v[0] v[1] ... v[Nv-1]  r g b a
    */

  int x, y, z, indice;
  indice = 0;
  float lado = 0.5;
  int numeroVertices = 0;
  int numeroFaces = 0;

  std::ofstream arquivoGerado; // Cria um objeto do tipo ofstream para escrever

  fixed(arquivoGerado); // Define a precisão de saída

  arquivoGerado.open(filename); // Abre o arquivo para escrita

  // Verifica se foi possível abrir o arquivo, caso contrário encerra o programa
  if (arquivoGerado.is_open())
  {
    std::cout << "Arquivo aberto com sucesso" << std::endl;
  }
  else
  {
    std::cout << "Não foi possível abrir o arquivo." << std::endl;
    exit(1); // Encerra o programa com código de erro 1, EXIT_FAILURE
  }

  // Escreve OFF no arquivo
  arquivoGerado << "OFF\n";

  // Laço para identificar a quantidade de vertices e faces do voxel
  for (x = 0; x < nx; x++)
  {
    for (y = 0; y < ny; y++)
    {
      for (z = 0; z < nz; z++)
      {
        if (v[x][y][z].show)
        {
          numeroVertices += 8;
          numeroFaces += 6;
        }
      }
    }
  }

  // Escreve o número de vértices e faces no arquivo
  // x[0]  y[0]  z[0]
  arquivoGerado << numeroVertices << " " << numeroFaces
                << " 0 \n"; //   VÉRTICES, FACES, ARESTAS = 0

  // Laço que escreve as posições dos vértices
  for (x = 0; x < nx; x++)
  {
    for (y = 0; y < ny; y++)
    {
      for (z = 0; z < nz; z++)
      {
        if (v[x][y][z].show)
        {
          //  VÉRTICES DO VOXEL EM FORMATO DE CUBO
          arquivoGerado << x - lado << " " << y + lado << " " << z - lado
                        << std::endl; // Vértice 0
          arquivoGerado << x - lado << " " << y - lado << " " << z - lado
                        << std::endl; // Vértice 1
          arquivoGerado << x + lado << " " << y - lado << " " << z - lado
                        << std::endl; // Vértice 2
          arquivoGerado << x + lado << " " << y + lado << " " << z - lado
                        << std::endl; // Vértice 3
          arquivoGerado << x - lado << " " << y + lado << " " << z + lado
                        << std::endl; // Vértice 4
          arquivoGerado << x - lado << " " << y - lado << " " << z + lado
                        << std::endl; // Vértice 5
          arquivoGerado << x + lado << " " << y - lado << " " << z + lado
                        << std::endl; // Vértice 6
          arquivoGerado << x + lado << " " << y + lado << " " << z + lado
                        << std::endl; // Vértice 7
        }
      }
    }
  }

  // Escreve a conexao dos vertices para formar as faces e suas cores
  for (int x = 0; x < nx; x++)
  {
    for (int y = 0; y < ny; y++)
    {
      for (int z = 0; z < nz; z++)
      {
        if (v[x][y][z].show)
        {
          // o incide  garante que os pontos do cubo atual não se
          // sobreponham aos pontos do cubo anterior no arquivo de saída.

          arquivoGerado << 4 << ' ' << indice + 0 << ' ' << indice + 3 << ' '
                        << indice + 2 << ' ' << indice + 1 << ' '
                        << v[x][y][z].r << ' ' << v[x][y][z].g << ' '
                        << v[x][y][z].b << ' ' << v[x][y][z].a << std::endl;

          arquivoGerado << 4 << ' ' << indice + 4 << ' ' << indice + 5 << ' '
                        << indice + 6 << ' ' << indice + 7 << ' '
                        << v[x][y][z].r << ' ' << v[x][y][z].g << ' '
                        << v[x][y][z].b << ' ' << v[x][y][z].a << std::endl;

          arquivoGerado << 4 << ' ' << indice + 0 << ' ' << indice + 1 << ' '
                        << indice + 5 << ' ' << indice + 4 << ' '
                        << v[x][y][z].r << ' ' << v[x][y][z].g << ' '
                        << v[x][y][z].b << ' ' << v[x][y][z].a << std::endl;

          arquivoGerado << 4 << ' ' << indice + 0 << ' ' << indice + 4 << ' '
                        << indice + 7 << ' ' << indice + 3 << ' '
                        << v[x][y][z].r << ' ' << v[x][y][z].g << ' '
                        << v[x][y][z].b << ' ' << v[x][y][z].a << std::endl;

          arquivoGerado << 4 << ' ' << indice + 3 << ' ' << indice + 7 << ' '
                        << indice + 6 << ' ' << indice + 2 << ' '
                        << v[x][y][z].r << ' ' << v[x][y][z].g << ' '
                        << v[x][y][z].b << ' ' << v[x][y][z].a << std::endl;

          arquivoGerado << 4 << ' ' << indice + 1 << ' ' << indice + 2 << ' '
                        << indice + 6 << ' ' << indice + 5 << ' '
                        << v[x][y][z].r << ' ' << v[x][y][z].g << ' '
                        << v[x][y][z].b << ' ' << v[x][y][z].a << std::endl;

          indice += 8;
        }
      }
    }
  }
  // Fecha o arquivo
  arquivoGerado.close();
  std::cout << filename << " foi criado com sucesso!" << std::endl;
}