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

void gerarEspaco(Sculptor &s, int x, int z){
  s.setColor(0.0, 0.7, 0.0, 1.0); 

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < z; j++) {
      s.putVoxel(i, 0, j);
    }
  }
}

void criarCampo(Sculptor &s, int x, int y, int z) {
    // Desenha o campo de futebol como um retângulo
    s.setColor(0.0, 0.7, 0.0, 1.0); // Cor verde para o campo

    int mudarFaixa = 0;
    // Desenhando metade do campo 
    for (int i = 34; i < 75; i++) {
        // mudarFaixa++;
        
        // Desenhando faixas no campo de futebol
        if(i % 5 == 0 || i == 0){
          if(mudarFaixa == 0){
            s.setColor(0.0, 0.5, 0.0, 1.0); // Cor verde mais escuro para o campo
            mudarFaixa = 1;          
          }else{
            s.setColor(0.0, 0.7, 0.0, 1.0); // Cor verde para o campo
            mudarFaixa = 0;
          }
        }

        for (int j = 44; j < 105; j++) {
            s.putVoxel(i, 0, j);
            std::cout << i << std::endl;
            std::cout << j << std::endl;
        }
    }

    // Desenhando linha no centro
    s.setColor(1.0, 1.0, 1.0, 1.0); // Cor branca para o campo
    for (int j = 44; j < 105; j++) {
        s.putVoxel(75, 0, j);
    }

    // Desenhando a outra metade do campo
    if(mudarFaixa == 1){
      s.setColor(0.0, 0.5, 0.0, 1.0); // Cor verde mais escuro para o campo
    }else{
      s.setColor(0.0, 0.7, 0.0, 1.0); // Cor verde para o campo
    }

    for (int i = 75; i < 110; i++) {
        // mudarFaixa++;
        
        // Desenhando faixas no campo de futebol
        if(i % 5 == 0 || i == 0){
          if(mudarFaixa == 0){
            s.setColor(0.0, 0.5, 0.0, 1.0); // Cor verde mais escuro para o campo
            mudarFaixa = 1;          
          }else{
            s.setColor(0.0, 0.7, 0.0, 1.0); // Cor verde para o campo
            mudarFaixa = 0;
          }
        }

        for (int j = 44; j < 105; j++) {
            s.putVoxel(i + 1, 0, j);
        }
    }

    // Desenhando as linhas externas do campo 
    s.setColor(1.0, 1.0, 1.0, 1.0); // Cor branca para o campo
    for (int i = 35 ; i < 116; i++) {
        s.putVoxel(i, 0, 44);
        s.putVoxel(i, 0, 104);
    }
    for (int j = 44; j < 105; j++) {
        s.putVoxel(35, 0, j);
        s.putVoxel(115, 0, j);
    }

    // Adicionando perimetro do circulo central
    for (int i = 0; i < 360; i++) {
        double x = 75 + 7 * cos(i * M_PI / 180);
        double z = 75 + 7 * sin(i * M_PI / 180);
        s.putVoxel(x, 0, z);
    }

    // Adicionando retangulo grande de area
    for (int i = 35; i < 51; i++) {
        // Linhas do lado direito 
        s.putVoxel(i, 0, 60);
        s.putVoxel(i, 0, 90);
        // Linhas do lado esquerdo
        s.putVoxel(i + 65, 0, 60);
        s.putVoxel(i + 65, 0, 90);
    }
    for(int i = 45; i < 76; i++){
        // Linhas do lado direito
        s.putVoxel(50, 0, i + 15);
        // Linha do lado esquerdo
        s.putVoxel(100, 0, i + 15);
    }

    // Adicionando meia lua no centro do retangulo grande
    for (int i = 0; i < 180; i++) {
        // meia lua do lado direito
        double x = 51 + 5 * sin(i * M_PI / 180);
        double z = 75 + 5 * cos(i * M_PI / 180);
        
        if(x - 2 > 51){
            s.putVoxel(x - 2, 0, z);
        }

        // meia lua do lado esquerdo
        double x2 = 100 - 5 * sin(i * M_PI / 180);
        double z2 = 75 + 5 * cos(i * M_PI / 180);

        if(x2 + 2 < 100){
            s.putVoxel(x2 + 2, 0, z2);
        }
        
    }

    // Adicionando retangulo pequeno de area
    // x 
    for (int i = 35; i < 41; i++) {
        // Linhas do lado direito
        s.putVoxel(i, 0, 67);
        s.putVoxel(i, 0, 84);
        // Linhas do lado esquerdo
        s.putVoxel(i + 75, 0, 67);
        s.putVoxel(i + 75, 0, 84);
    }
    // z 
    for(int i = 34; i < 51; i++){
        // Linhas do lado direito
        s.putVoxel(40, 0, i + 34);
        // Linhas do lado esquerdo
        s.putVoxel(110, 0, i + 34);
    }
}

void criarArquibancada(Sculptor &s){
    // definindo cor cinza para a arquibancada 
    s.setColor(0.5, 0.5, 0.5, 1.0);

    // Arquibancada frente inferior 

    for (int i = 0; i < 10; i++) {
        // Desenhando arquibancada frente inferior (regressão em z) 
        // a1 
        int startX = 35, startY = 1, startZ = 40;

        for(int xc = startX; xc < 116; xc++){
            s.putVoxel(xc, startY + i, startZ - i);
            s.putVoxel(xc, startY + i, startZ - i + 1); // Adiciona um voxel na frente do outro
        }
        // Desenhando arquivancada lateral (regressão em x)
        // a2
        startX = 25, startY = 1, startZ = 51;

        for(int zc = startZ; zc < 98; zc++){
            s.putVoxel(startX - i, startY + i, zc);
            s.putVoxel(startX - i + 1, startY + i, zc); // Adiciona um voxel na frente do outro
        }

        // Desenhando arquibancada frente inferior (progressão em z) 
        // a3
        startX = 35, startY = 1, startZ = 107;

        for(int xc = startX; xc < 116; xc++){
            s.putVoxel(xc, startY + i, startZ + i);
            s.putVoxel(xc, startY + i, startZ + i + 1); // Adiciona um voxel na frente do outro
        }

        // Desenhando arquibancada frente superior 2 (regressão em z)
        // a7
        startX = 35, startY = 21, startZ = 30; //diminuindo 10 em z em relação a a4 (superior)

        for(int xc = startX; xc < 116; xc++){
            s.putVoxel(xc, startY + i, startZ - i);
            s.putVoxel(xc, startY + i, startZ - i + 1); // Adiciona um voxel na frente do outro
        }

        // Desenhando arquibancada lateral superior 2 (regressão em x)
        // a8
        startX = 15, startY = 21, startZ = 51; //diminuindo 5 em x em relação a a5 (superior)

        for(int zc = startZ; zc < 98; zc++){
            s.putVoxel(startX - i, startY + i, zc);
            s.putVoxel(startX - i + 1, startY + i, zc); // Adiciona um voxel na frente do outro
        }

        // Desenhando arquibancada frente superior 2 (progressão em z)
        // a9
        startX = 35, startY = 21, startZ = 117; //aumentando 5 em z em relação a a6 (superior)

        for(int xc = startX; xc < 116; xc++){
            s.putVoxel(xc, startY + i, startZ + i);
            s.putVoxel(xc, startY + i, startZ + i + 1); // Adiciona um voxel na frente do outro
        }
    }

    // Gerando arquibancada central 
    s.setColor(0.3, 0.3, 0.3, 1);
    for (int i = 0; i < 6; i++){
      
        // Desenhando arquibancada frente superior (regressão em z) 
        // a4 
        int startX = 35, startY = 13, startZ = 35; //diminuindo 5 em z em relação a a1 (inferior)

        for(int xc = startX; xc < 116; xc++){
            s.putVoxel(xc, startY + i, startZ - i);
            s.putVoxel(xc, startY + i, startZ - i + 1); // Adiciona um voxel na frente do outro
        }

        // Desenhando arquibancada lateral (regressão em x)
        // a5
        startX = 20, startY = 13, startZ = 51; //diminuindo 5 em x em relação a a2 (inferior)

        for(int zc = startZ; zc < 98; zc++){
            s.putVoxel(startX - i, startY + i, zc);
            s.putVoxel(startX - i + 1, startY + i, zc); // Adiciona um voxel na frente do outro
        }

        // Desenhando arquibancada frente superior (progressão em z)
        // a6
        startX = 35, startY = 13, startZ = 112; //aumentabdi 5 em z em relação a a3 (inferior)

        for(int xc = startX; xc < 116; xc++){
            s.putVoxel(xc, startY + i, startZ + i);
            s.putVoxel(xc, startY + i, startZ + i + 1); // Adiciona um voxel na frente do outro
        }
    }
    
    s.setColor(0.5, 0.5, 0.5, 1.0);
    for (int nivel = 0; nivel < 10; nivel++) {
        // Escada curva (1/4 de circunferência)
        
        // Curva inferior c1 
        for (int i = 180; i < 270; i++) {
            double x = 35 + (9 + nivel)* cos(i * M_PI / 180);
            double z = 50 + (9 + nivel) * sin(i * M_PI / 180);
            s.putVoxel(x, 1 + nivel, z);
        }

        // Curva inferior c2 
        for (int i = 90; i < 180; i++) {
            double x = 35 + (9 + nivel)* cos(i * M_PI / 180);
            double z = 98 + (9 + nivel) * sin(i * M_PI / 180);
            s.putVoxel(x, 1 + nivel, z);
        }

        // Curva superior c5
        for (int i = 180; i < 270; i++) {
            double x = 35 + (19 + nivel)* cos(i * M_PI / 180);
            double z = 50 + (19 + nivel) * sin(i * M_PI / 180);
            s.putVoxel(x, 21 + nivel, z);
        }

        // Curva superior c6
        for (int i = 90; i < 180; i++) {
            double x = 35 + (19 + nivel)* cos(i * M_PI / 180);
            double z = 98 + (19 + nivel) * sin(i * M_PI / 180);
            s.putVoxel(x, 21 + nivel, z);
        }
    }

    // Curvas centrais 
    s.setColor(0.3, 0.3, 0.3, 1);
    for (int nivel = 0; nivel < 6; nivel++){
      // Curva superior c3
      for (int i = 180; i < 270; i++) {
          double x = 35 + (14 + nivel)* cos(i * M_PI / 180);
          double z = 50 + (14 + nivel) * sin(i * M_PI / 180);
          s.putVoxel(x, 13 + nivel, z);
      }

      // Curva superior c4
      for (int i = 90; i < 180; i++) {
          double x = 35 + (14 + nivel)* cos(i * M_PI / 180);
          double z = 98 + (14 + nivel) * sin(i * M_PI / 180);
          s.putVoxel(x, 13 + nivel, z);
      }
    }

    s.setColor(0.0, 0.5, 0.5, 1);   
}

void criarEstruturaEstadio(Sculptor &s){
    // construindo parede do estádio 
    for (int i = 0; i < 33; i++) {

        // Parede frontal
        for (int j = 35; j < 116; j++) {
            if( j > 65 && j < 86){
                s.setColor(0.5, 0.5, 0.5, 1.0);
                s.putVoxel(j, i, 15-1);
            }else{
                s.setColor(0.0, 0.0, 0.3, 0.1);
                s.putVoxel(j, i, 15);
            }
        }

        // Parede traseira
        for (int j = 35; j < 116; j++) {
            if( j > 65 && j < 86){
                s.setColor(0.5, 0.5, 0.5, 1.0);
                s.putVoxel(j, i, 135);
            }else{
                s.setColor(0.0, 0.0, 0.3, 0.1);
                s.putVoxel(j, i, 136);
            }
        }

        // Parede lateral esquerda
        for (int j = 49; j < 102; j++) {
            if( j > 65 && j < 84){
                s.setColor(0.5, 0.5, 0.5, 1.0);
                s.putVoxel(2, i, j);
            }else{
                s.setColor(0.0, 0.0, 0.3, 0.1);
                s.putVoxel(3, i, j);
            }
        }

        for (int j = 180; j < 270; j++) {
            double x = 35 + (32)* cos(j * M_PI / 180);
            double z = 48 + (32) * sin(j * M_PI / 180);
            s.putVoxel(x, i, z);
        }

        for (int j = 90; j < 180; j++) {
            double x = 35 + (32)* cos(j * M_PI / 180);
            double z = 102 + (32) * sin(j * M_PI / 180);
            s.putVoxel(x, i, z);
        }
    }

    // Adicionando cobertura ao estádio 
    // Frente e traseira
    for (int j = 38; j < 116; j++) {
        for (int k = 15; k < 40; k++) {
            if(j > 63 && j < 86){
                s.setColor(0.5, 0.5, 0.5, 1.0);
                s.putVoxel(j, 33, k);
            }else{
                s.setColor(0.0, 0.0, 0.3, 0.1);
                s.putVoxel(j, 32, k);
            }
        }

        for (int k = 135; k > 110; k--) {
            if(j > 65 && j < 86){
                s.setColor(0.5, 0.5, 0.5, 1.0);
                s.putVoxel(j, 33, k);
            }else{
                s.setColor(0.0, 0.0, 0.3, 0.1);
                s.putVoxel(j, 32, k);
            }
        }
    }

    // Laterais
    // inserir circulo preenchido
    for (int j = 180; j < 270; j++) {
        double x = 35 + (32)* cos(j * M_PI / 180);
        double z = 48 + (32) * sin(j * M_PI / 180);
        s.putVoxel(x, 33, z);
    }

    s.setColor(0.3, 0.3, 0.3, 1);
    s.putBox(115, 125, 1, 32, 15, 41);
    s.putBox(115, 125, 1, 32, 108, 136);
    
    s.setColor(0.0, 0.0, 0.3, 0.1);
    s.putBox(118, 125, 1, 5, 42, 107);
}

// Função principal
int main() {
  // Dimensões da escultura
  int nx = 150, ny = 50, nz = 150;

  // Criando o objeto Sculptor
  Sculptor sculptor(nx, ny, nz);

  // Criando a flor com as dimensões definidas
  gerarEspaco(sculptor, 150, 150);
  criarCampo(sculptor, nx, ny, nz);
  criarArquibancada(sculptor);
  criarEstruturaEstadio(sculptor);

  std::cout << "Escultura criada com sucesso!" << std::endl;

  // Salvando a escultura em um arquivo OFF
  sculptor.writeOFF("field.off");

  return 0;
}