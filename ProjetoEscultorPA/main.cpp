#include "sculptor.hpp"
#include <cmath>
#include <iostream>
#include <vector>

// Funções auxiliares
double square(double x) { return x * x; }

double mod2(double a, double b) {
  double c = fmod(a, b);
  return c > 0 ? c : c + b;
}

// Função para criar a flor
void createFlower(Sculptor &sculptor, int nx, int ny, int nz) {
  const double PI = M_PI;
  double theta1 = -(20.0 / 9.0) * PI;
  double theta2 = 15 * PI;

  // Cores para as pétalas
  std::vector<std::vector<double>> colors = {
      {1.0, 0.0, 0.0, 1.0}, // Vermelho
      {0.0, 1.0, 0.0, 1.0}, // Verde
      {0.0, 0.0, 1.0, 1.0}, // Azul
      {1.0, 1.0, 0.0, 1.0}, // Amarelo
      {1.0, 0.0, 1.0, 1.0}, // Magenta
      {0.0, 1.0, 1.0, 1.0}  // Ciano
  };

  for (double u = 0; u <= 1; u += 1.0 / 24) {
    // Mudar a cor para cada camada
    sculptor.setColor(0.0, 0.0, 0.0, 1.0);  // Preto

    for (double theta = theta1; theta <= theta2;
         theta += (theta2 - theta1) / 575) {
      double phi = (PI / 2) * exp(-theta / (8 * PI));
      double y1 = 1.9565284531299512 * square(u) *
                  square(1.2768869870150188 * u - 1) * sin(phi);
      double X =
          1 -
          square(1.25 * square(1 - mod2(3.6 * theta, 2 * PI) / PI) - 0.25) / 2;
      double r = X * (u * sin(phi) + y1 * cos(phi));

      double xCoord = r * sin(theta);
      double yCoord = r * cos(theta);
      double zCoord = X * (u * cos(phi) - y1 * sin(phi));

      // Convertendo coordenadas para o sistema de coordenadas da escultura
      int x = static_cast<int>((xCoord + 1.0) * nx / 2.0);
      int y = static_cast<int>((yCoord + 1.0) * ny / 2.0);
      int z = static_cast<int>((zCoord + 1.0) * nz / 2.0);

      // Garantindo que as coordenadas estão dentro dos limites da escultura
      if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        sculptor.putVoxel(x, y, z);
      }
    }
  }
}

void createField(Sculptor &s, int x, int y, int z) {
    std::cout << "0" << std::endl;
    
    // Desenha o campo de futebol como um retângulo
    s.setColor(0.0, 1.0, 0.0, 1.0); // Cor verde para o campo
    std::cout << "0.5" << std::endl;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 30; j++) {
            s.putVoxel(i, j, 0);
        }
    }

    //Printandoi sucesso
    std::cout << "1!" << std::endl;

}

// Função principal
int main() {
  // Dimensões da escultura
  int nx = 100, ny = 100, nz = 100;

  // Criando o objeto Sculptor
  Sculptor sculptor(nx, ny, nz);

  // Criando a flor com as dimensões definidas
  // createFlower(sculptor, nx, ny, nz);
  createField(sculptor, nx, ny, nz);

  std::cout << "Escultura criada com sucesso!" << std::endl;

  // Salvando a escultura em um arquivo OFF
  sculptor.writeOFF("field.off");

  return 0;
}