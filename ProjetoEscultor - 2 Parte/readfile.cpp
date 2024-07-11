#include "readfile.h"
#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include "sculptor.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

ReadFile::ReadFile() {}

void ReadFile::read(std::vector<FiguraGeometrica *> &desenho, Sculptor *&t,
                    const char *filename)
{
  fin.open(filename);
  if (!fin.is_open())
  {
    std::cerr << "Erro: Não foi possível abrir o arquivo " << filename << std::endl;
    exit(1);
  }

  std::cout << "Arquivo " << filename << " aberto com sucesso." << std::endl;
  std::cout << "Iniciando leitura do arquivo..." << std::endl;

  while (std::getline(fin, line, '\n'))
  {
    std::stringstream linha(line);

    std::vector<std::string> v;
    while (linha.good())
    {
      linha >> palavra;
      v.push_back(palavra);
    }
    if (v.empty())
      continue;

    if (v[0] == "dim") {
      t = new Sculptor(v);
      std::cout << "Dimensões do escultor definidas: " << v[1] << " x " << v[2] << " x " << v[3] << std::endl;
    } else if (v[0] == "putvoxel") {
      desenho.push_back(new PutVoxel(v));
      std::cout << "Adicionado PutVoxel com parâmetros: " << line << std::endl;
    } else if (v[0] == "cutvoxel") {
      desenho.push_back(new CutVoxel(v));
      std::cout << "Adicionado CutVoxel com parâmetros: " << line << std::endl;
    } else if (v[0] == "putbox") {
      desenho.push_back(new PutBox(v));
      std::cout << "Adicionado PutBox com parâmetros: " << line << std::endl;
    } else if (v[0] == "cutbox") {
      desenho.push_back(new CutBox(v));
      std::cout << "Adicionado CutBox com parâmetros: " << line << std::endl;
    } else if (v[0] == "putsphere") {
      desenho.push_back(new PutSphere(v));
      std::cout << "Adicionado PutSphere com parâmetros: " << line << std::endl;
    } else if (v[0] == "cutsphere") {
      desenho.push_back(new CutSphere(v));
      std::cout << "Adicionado CutSphere com parâmetros: " << line << std::endl;
    } else if (v[0] == "putellipsoid") {
      desenho.push_back(new PutEllipsoid(v));
      std::cout << "Adicionado PutEllipsoid com parâmetros: " << line << std::endl;
    } else if (v[0] == "cutellipsoid") {
      desenho.push_back(new CutEllipsoid(v));
      std::cout << "Adicionado CutEllipsoid com parâmetros: " << line << std::endl;
    } else {
      std::cerr << "Comando não reconhecido: " << v[0] << std::endl;
    }
  }
  fin.close();
  std::cout << "Leitura do arquivo concluída." << std::endl;
}

ReadFile::~ReadFile() {}