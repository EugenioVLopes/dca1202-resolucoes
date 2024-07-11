#include "sculptor.h"
#include <fstream>
#include <iostream>
#include <vector>

int Sculptor::getNx() const { return nx; }

int Sculptor::getNy() const { return ny; }

int Sculptor::getNz() const { return nz; }

void Sculptor::putVoxel(int x, int y, int z)
{
  if (v[x][y][z].show == 1)
  {
    v[x][y][z].show = 0;
    Nvertices -= 8;
    Nfaces -= 6;
  }

  if ((x >= 0 && x <= nx) && (y >= 0 && y <= ny) && (z >= 0 && z <= nz))
  {
    v[x][y][z].show = 1;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    Nvertices += 8;
    Nfaces += 6;
  }
}

void Sculptor::cutVoxel(int x, int y, int z)
{
  if (((x >= 0 && x <= nx) && (y >= 0 && y <= ny) && (z >= 0 && z <= nz)) &&
      v[x][y][z].show == 1)
  {
    v[x][y][z].show = 0;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    Nvertices -= 8;
    Nfaces -= 6;
  }
}

void Sculptor::writeOFF(const char *filename)
{
  std::ofstream arquivoGerado;
  arquivoGerado.open(filename);
  int plus8 = 0;
  if (!arquivoGerado.is_open())
  {
    std::cout << "Não foi possível abrir o arquivo." << std::endl;
    exit(1); // Encerra o programa com código de erro 1, EXIT_FAILURE
  }
  else
  {
    std::cout << "Arquivo aberto com sucesso" << std::endl;
    arquivoGerado << "OFF" << std::endl;

    arquivoGerado << Nvertices << " " << Nfaces << " " << 0 << std::endl;

    // std::cout << nx << std::endl;
    // std::cout << ny << std::endl;
    // std::cout << nz << std::endl;

    for (int i = 0; i < nx; i++)
      for (int j = 0; j < ny; j++)
        for (int k = 0; k < nz; k++)
        {
          if (v[i][j][k].show == 1)
          {

            arquivoGerado << i + 0.5 << ' ' << j + 0.5 << ' ' << k + 0.5 << std::endl;
            arquivoGerado << i + 0.5 << ' ' << j + 0.5 << ' ' << k - 0.5 << std::endl;
            arquivoGerado << i + 0.5 << ' ' << j - 0.5 << ' ' << k + 0.5 << std::endl;
            arquivoGerado << i + 0.5 << ' ' << j - 0.5 << ' ' << k - 0.5 << std::endl;
            arquivoGerado << i - 0.5 << ' ' << j + 0.5 << ' ' << k + 0.5 << std::endl;
            arquivoGerado << i - 0.5 << ' ' << j + 0.5 << ' ' << k - 0.5 << std::endl;
            arquivoGerado << i - 0.5 << ' ' << j - 0.5 << ' ' << k + 0.5 << std::endl;
            arquivoGerado << i - 0.5 << ' ' << j - 0.5 << ' ' << k - 0.5 << std::endl;
          }
        }

    for (int i = 0; i < nx; i++)
      for (int j = 0; j < ny; j++)
        for (int k = 0; k < nz; k++)
        {
          if (v[i][j][k].show == 1)
          {

            arquivoGerado << 4 << ' ' << 0 + 8 * plus8 << ' ' << 2 + 8 * plus8 << ' '
                          << 3 + 8 * plus8 << ' ' << 1 + 8 * plus8 << ' ' << v[i][j][k].r
                          << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '
                          << v[i][j][k].a << std::endl;

            arquivoGerado << 4 << ' ' << 0 + 8 * plus8 << ' ' << 1 + 8 * plus8 << ' '
                          << 5 + 8 * plus8 << ' ' << 4 + 8 * plus8 << ' ' << v[i][j][k].r
                          << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '
                          << v[i][j][k].a << std::endl;

            arquivoGerado << 4 << ' ' << 0 + 8 * plus8 << ' ' << 2 + 8 * plus8 << ' '
                          << 6 + 8 * plus8 << ' ' << 4 + 8 * plus8 << ' ' << v[i][j][k].r
                          << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '
                          << v[i][j][k].a << std::endl;

            arquivoGerado << 4 << ' ' << 7 + 8 * plus8 << ' ' << 5 + 8 * plus8 << ' '
                          << 1 + 8 * plus8 << ' ' << 3 + 8 * plus8 << ' ' << v[i][j][k].r
                          << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '
                          << v[i][j][k].a << std::endl;

            arquivoGerado << 4 << ' ' << 7 + 8 * plus8 << ' ' << 3 + 8 * plus8 << ' '
                          << 2 + 8 * plus8 << ' ' << 6 + 8 * plus8 << ' ' << v[i][j][k].r
                          << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '
                          << v[i][j][k].a << std::endl;

            arquivoGerado << 4 << ' ' << 7 + 8 * plus8 << ' ' << 6 + 8 * plus8 << ' '
                          << 4 + 8 * plus8 << ' ' << 5 + 8 * plus8 << ' ' << v[i][j][k].r
                          << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '
                          << v[i][j][k].a << std::endl;

            plus8 += 1;
          }
        }
  }

  arquivoGerado.close();
  std::cout << filename << " foi criado com sucesso!" << std::endl;
}

Sculptor::Sculptor(std::vector<std::string> vt)
{
  nx = std::stoi(vt[1]);
  ny = std::stoi(vt[2]);
  nz = std::stoi(vt[3]);

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

Sculptor::~Sculptor()
{
  delete[] v[0][0];
  delete[] v[0];
  delete v;
}

void Sculptor::setColor(float r, float g, float b, float a)
{
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}