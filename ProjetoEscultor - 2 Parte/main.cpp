#include "figurageometrica.h"
#include "putvoxel.h"
#include "readfile.h"
#include "sculptor.h"
#include <iostream>

int main(void) {
  
  std::vector<FiguraGeometrica *> desenho;
  Sculptor *t;
  ReadFile aux;

  aux.read(desenho, t,
           "teste7.txt");

  for (int i = 0; i < int(desenho.size()); i++)
    desenho[i]->draw(*t);

  t->writeOFF("desenho.off");

  for (int i = 0; i < int(desenho.size()); i++)
    delete desenho[i];

  delete t;
  return 0;
}