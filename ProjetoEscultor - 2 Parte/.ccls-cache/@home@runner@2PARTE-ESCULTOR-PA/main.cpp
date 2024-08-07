#include "figurageometrica.h"
#include "putvoxel.h"
#include "readoff.h"
#include "sculptor.h"
#include <iostream>

int main(void) {
  std::vector<FiguraGeometrica *> desenho;
  Sculptor *t;
  ReadOff aux;

  aux.read(desenho, t,
           "teste.txt");

  for (int i = 0; i < int(desenho.size()); i++)
    desenho[i]->draw(*t);

  t->writeOFF("desenho.off");

  std::cout << desenho.size();

  for (int i = 0; i < int(desenho.size()); i++)
    delete desenho[i];

  delete t;
  return 0;
}