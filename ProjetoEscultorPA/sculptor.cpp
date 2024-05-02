#include "sculptor.hpp"

#include <cmath>
#include <fstream>
#include <iostream>

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
  // Atribuição os valores de nx, ny e nz para o objeto Sculptor
  nx = _nx;
  ny = _ny;
  nz = _nz;

  v = new Voxel **[nx]; // Aloca memória para o array de ponteiros de ponteiros
  v[0] = new Voxel *[nx * ny];       // Aloca memória para o array de ponteiros
  v[0][0] = new Voxel[nx * ny * nz]; // Aloca memória

  // Verificando se a memória foi alocada corretamente
  if (v == nullptr || v[0] == nullptr || v[0][0] == nullptr) {
    printf("Memória insuficiente\n");
    exit(0);
  }

  // Laço de ajuste de posições de memória no array de v
  for (int i = 1; i < nx; i++) {
    v[i] = v[0] + i * ny;
  }
  for (int i = 1; i < nx * ny; i++) {
    v[0][i] = v[0][0] + i * nz;
  }
  std ::cout << "objeto 3D criado: " << nx << " x " << ny << " x " << nz
             << std ::endl;
}

Sculptor::~Sculptor() {
  // Implementação do destrutor liberando as memórias alocadas
  delete[] v[0][0];
  delete[] v[0];
  delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float a) {
  // Implementação do método setColor
  if (r >= 0 && r <= 1.0 && g >= 0 && g <= 1.0 && b >= 0 && b <= 1.0 &&
      a >= 0 && a <= 1.0) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
  }
}

void Sculptor::putVoxel(int x, int y, int z) {
  // Implementação do método putVoxel => Adição do Voxel
  v[x][y][z].r = r;
  v[x][y][z].g = g;
  v[x][y][z].b = b;
  v[x][y][z].a = a;
  v[x][y][z].show = true;
}

void Sculptor::cutVoxel(int x, int y, int z) {
  // Implementação do método cutVoxel => Remoção do Voxel
  v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
  // Implementação do método putBox => Adição de uma caixa/cubo
  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= y1; j++) {
      for (int k = z0; k <= z1; k++) {
        putVoxel(i, j, k);
      }
    }
  }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y, int z0, int z1) {
  // Implementação do método cutBox => Remoção de uma caixa/cubo
  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= y; j++) {
      for (int k = z0; k <= z1; k++) {
        cutVoxel(i, j, k);
      }
    }
  }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
  // Implementação do método putSphere => Adição de uma esfera
  double equation;
  /*
   *(x-x0)^2 + (y - y0)^2 + (z - z0)^2 <= r^2
   */
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        equation =
            pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
        if (equation <= pow(radius, 2)) {
          // Preenche apenas os pontos de dentro da esfera
          putVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
  // Implementação do método cutSphere => Remoção de uma esfera
  double equation;

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        equation =
            pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
        if (equation <= pow(radius, 2)) {

          // 'Corta' apenas os pontos de dentro da esfera
          cutVoxel(i, j, k);
        }
      }
    }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz) {
  // Implementação do método putEllipsoid => Adição de uma elipsoide
  double equation;

  /*
     *(x - a)^2 + (y - b)^2 + (z - c)^2 <= 1
      x=0 , y=0 , z=0
      a=xcenter; b=ycenter; c=zcenter
    */
  if (rx == 0) {
    for (int pz = 0; pz <= nz; pz++) {
      for (int py = 0; py <= ny; py++) {
        equation = (pow(py - ycenter, 2) / pow(ry, 2)) +
                   (pow(pz - zcenter, 2) / pow(rz, 2));
        if (equation <= 1) {
          putVoxel(xcenter, py, pz);
        }
      }
    }
  } else if (ry == 0) {
    for (int pz = 0; pz <= nz; pz++) {
      for (int px = 0; px <= nx; px++) {
        equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                   (pow(pz - zcenter, 2) / pow(rz, 2));
        if (equation <= 1) {
          putVoxel(px, ycenter, pz);
        }
      }
    }
  } else if (rz == 0) {
    for (int py = 0; py <= ny; py++) {
      for (int px = 0; px <= nx; px++) {
        equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                   (pow(py - ycenter, 2) / pow(ry, 2));
        if (equation <= 1) {
          putVoxel(px, py, zcenter);
        }
      }
    }
  } else {
    for (int pz = 0; pz <= nz; pz++) {
      for (int py = 0; py <= ny; py++) {
        for (int px = 0; px <= nx; px++) {
          equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                     (pow(py - ycenter, 2) / pow(ry, 2)) +
                     (pow(pz - zcenter, 2) / pow(rz, 2));
          if (equation <= 1) {
            putVoxel(px, py, pz);
          }
        }
      }
    }
  }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz) {
  // Implementação do método cutEllipsoid => Remoção de uma elipsoide

  double equation;

  if (rx == 0) {
    for (int pz = 0; pz <= nz; pz++) {
      for (int py = 0; py <= ny; py++) {
        equation = (pow(py - ycenter, 2) / pow(ry, 2)) +
                   (pow(pz - zcenter, 2) / pow(rz, 2));
        if (equation <= 1) {
          cutVoxel(xcenter, py, pz);
        }
      }
    }
  } else if (ry == 0) {
    for (int pz = 0; pz <= nz; pz++) {
      for (int px = 0; px <= nx; px++) {
        equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                   (pow(pz - zcenter, 2) / pow(rz, 2));

        if (equation <= 1) {
          cutVoxel(px, ycenter, pz);
        }
      }
    }
  } else if (rz == 0) {
    for (int py = 0; py <= ny; py++) {
      for (int px = 0; px <= nx; px++) {
        equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                   (pow(py - ycenter, 2) / pow(ry, 2));

        if (equation <= 1) {
          cutVoxel(px, py, zcenter);
        }
      }
    }
  } else {
    for (int pz = 0; pz <= nz; pz++) {
      for (int py = 0; py <= ny; py++) {
        for (int px = 0; px <= nx; px++) {
          equation = (pow(px - xcenter, 2) / pow(rx, 2)) +
                     (pow(py - ycenter, 2) / pow(ry, 2)) +
                     (pow(pz - zcenter, 2) / pow(rz, 2));

          if (equation <= 1) {
            cutVoxel(px, py, pz);
          }
        }
      }
    }
  }
}

void Sculptor::writeOFF(const char *filename) {
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

  int x, y, z, voxelAtivo;
  voxelAtivo = 0;
  float lado = 0.5;
  int numeroVertices = 0;
  int numeroFaces = 0;

  // Abre o arquivo OFF para escrita
  std::ofstream arq;
  arq.open(filename);
  if (arq.is_open() == false) {
    std::cerr << "Erro ao abrir o arquivo" << std::endl;
  }

  // Escreve OFF no arquivo
  // OFF
  arq << "OFF\n";
  // Laço para identificar a quantidade de voxels ativos
  for (x = 0; x < nx; x++) {
    for (y = 0; y < ny; y++) {
      for (z = 0; z < nz; z++) {
        // o .show é verdadeiro se o voxel estiver ativo
        if (v[x][y][z].show) {
          numeroVertices += 8;
          numeroFaces += 6;
        }
      }
    }
  }
  // Escreve a quantidade de voxels ativos no arquivo OFF
  // x[0]  y[0]  z[0]
  arq << numeroVertices << " " << numeroFaces
      << " 0 \n"; //   VÉRTICES, FACES, ARESTAS = 0

  for (x = 0; x < nx; x++) {
    for (y = 0; y < ny; y++) {
      for (z = 0; z < nz; z++) {
        if (v[x][y][z].show) {
          //  VÉRTICES DO VOXEL EM FORMATO DE CUBO
          arq << x - lado << " " << y + lado << " " << z - lado
              << std::endl; // Vértice 0
          arq << x - lado << " " << y - lado << " " << z - lado
              << std::endl; // Vértice 1
          arq << x + lado << " " << y - lado << " " << z - lado
              << std::endl; // Vértice 2
          arq << x + lado << " " << y + lado << " " << z - lado
              << std::endl; // Vértice 3
          arq << x - lado << " " << y + lado << " " << z + lado
              << std::endl; // Vértice 4
          arq << x - lado << " " << y - lado << " " << z + lado
              << std::endl; // Vértice 5
          arq << x + lado << " " << y - lado << " " << z + lado
              << std::endl; // Vértice 6
          arq << x + lado << " " << y + lado << " " << z + lado
              << std::endl; // Vértice 7
        }
      }
    }
  }

  // escrevendo a conexao dos vertices para formar as faces e suas cores
  for (int x = 0; x < nx; x++) {
    for (int y = 0; y < ny; y++) {
      for (int z = 0; z < nz; z++) {
        if (v[x][y][z].show) {
          int indice = 0;
          // o incide  garante que os pontos do cubo atual não se
          // sobreponham aos pontos do cubo anterior no arquivo de saída.

          arq << 4 << ' ' << indice + 0 << ' ' << indice + 3 << ' '
              << indice + 2 << ' ' << indice + 1 << ' ' << v[x][y][z].r << ' '
              << v[x][y][z].g << ' ' << v[x][y][z].b << ' ' << v[x][y][z].a
              << std::endl;

          arq << 4 << ' ' << indice + 4 << ' ' << indice + 5 << ' '
              << indice + 6 << ' ' << indice + 7 << ' ' << v[x][y][z].r << ' '
              << v[x][y][z].g << ' ' << v[x][y][z].b << ' ' << v[x][y][z].a
              << std::endl;

          arq << 4 << ' ' << indice + 0 << ' ' << indice + 1 << ' '
              << indice + 5 << ' ' << indice + 4 << ' ' << v[x][y][z].r << ' '
              << v[x][y][z].g << ' ' << v[x][y][z].b << ' ' << v[x][y][z].a
              << std::endl;

          arq << 4 << ' ' << indice + 0 << ' ' << indice + 4 << ' '
              << indice + 7 << ' ' << indice + 3 << ' ' << v[x][y][z].r << ' '
              << v[x][y][z].g << ' ' << v[x][y][z].b << ' ' << v[x][y][z].a
              << std::endl;

          arq << 4 << ' ' << indice + 3 << ' ' << indice + 7 << ' '
              << indice + 6 << ' ' << indice + 2 << ' ' << v[x][y][z].r << ' '
              << v[x][y][z].g << ' ' << v[x][y][z].b << ' ' << v[x][y][z].a
              << std::endl;

          arq << 4 << ' ' << indice + 1 << ' ' << indice + 2 << ' '
              << voxelAtivo + 6 << ' ' << voxelAtivo + 5 << ' ' << v[x][y][z].r
              << ' ' << v[x][y][z].g << ' ' << v[x][y][z].b << ' '
              << v[x][y][z].a << std::endl;

          indice += 8;
        }
      }
    }
  }

  arq.close();
}