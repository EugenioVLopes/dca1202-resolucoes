#include "sculptor.hpp"
#include <cmath>
#include <iostream>

// Funções auxiliares
double square(double x) { return x * x; }

double mod2(double a, double b)
{
  double c = fmod(a, b);
  return c > 0 ? c : c + b;
}

// Função para criar a flor
void createFlower(Sculptor &sculptor, int nx, int ny, int nz)
{
  const double PI = M_PI;
  double theta1 = -(20.0 / 9.0) * PI;
  double theta2 = 15 * PI;

  // Criando o caule da flor
  sculptor.setColor(0.0, 1.0, 0.0, 1.0); // Verde
  for (int z = 0; z < nz / 2; z++)
  {
    sculptor.putVoxel(nx / 2, ny / 2, z);
  }

  for (double u = 0; u <= 1; u += 1.0 / 24)
  {
    sculptor.setColor(1.0, 0.0, 0.0, 1.0); // Vermelho

    for (double theta = theta1; theta <= theta2;
         theta += (theta2 - theta1) / 575)
    {
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

      int x = static_cast<int>((xCoord + 1.0) * nx / 2.0);
      int y = static_cast<int>((yCoord + 1.0) * ny / 2.0);
      int z = static_cast<int>((zCoord + 1.0) * nz / 2.0);

      if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz)
      {
        sculptor.putVoxel(x, y, z);
      }
    }
  }
}

int main()
{
  // Dimensões da escultura para a flor
  int nx_flower = 100, ny_flower = 100, nz_flower = 100;

  // Criando o objeto Sculptor para a flor
  Sculptor sculptor_flower(nx_flower, ny_flower, nz_flower);

  // Criando a flor com as dimensões definidas
  createFlower(sculptor_flower, nx_flower, ny_flower, nz_flower);

  // Salvando a escultura da flor em um arquivo OFF
  sculptor_flower.writeOFF("flower.off");

  // Dimensões da escultura para os testes
  int nx_test = 100, ny_test = 100, nz_test = 100;

  // Criando o objeto Sculptor para os testes
  Sculptor sculptor_test(nx_test, ny_test, nz_test);

  // Define a cor para vermelho e coloca um voxel
  sculptor_test.setColor(1.0, 0.0, 0.0, 1.0);
  sculptor_test.putVoxel(5, 5, 5);

  // Define a cor para verde e coloca uma caixa
  sculptor_test.setColor(0.0, 1.0, 0.0, 1.0);
  sculptor_test.putBox(10, 15, 10, 15, 10, 15);

  // Define a cor para laranja e coloca outra caixa ao lado
  sculptor_test.setColor(1.0, 0.5, 0.0, 1.0);
  sculptor_test.putBox(21, 26, 10, 15, 10, 15);
  sculptor_test.cutBox(21, 26, 10, 15, 10, 12); // Cortando a metade da caixa

  // Define a cor para azul e coloca uma esfera
  sculptor_test.setColor(0.0, 0.0, 1.0, 1.0);
  sculptor_test.putSphere(25, 25, 25, 10);

  // Define a cor para rosa e coloca outra esfera ao lado
  sculptor_test.setColor(1.0, 0.0, 1.0, 1.0);
  sculptor_test.putSphere(50, 25, 25, 10);
  sculptor_test.cutSphere(50, 25, 35, 5); // Cortando a esfera

  // Define a cor para amarelo e coloca uma elipsoide
  sculptor_test.setColor(1.0, 1.0, 0.0, 1.0);
  sculptor_test.putEllipsoid(60, 60, 40, 5, 10, 15);

  // Define a cor para cinza e coloca outra elipsoide ao lado
  sculptor_test.setColor(0.5, 0.5, 0.5, 1.0);
  sculptor_test.putEllipsoid(80, 60, 40, 5, 10, 16);
  sculptor_test.cutEllipsoid(80, 60, 40, 5, 10, 8); // Cortando a elipsoide

  // Salva a escultura de teste em um arquivo OFF
  sculptor_test.writeOFF("sculpture.off");

  std::cout << "Teste concluido. Verifique os arquivos flower.off e sculpture.off para ver os resultados." << std::endl;

  return 0;
}
