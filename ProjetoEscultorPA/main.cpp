#include "sculptor.hpp"
#include <iostream>

int main()
{
  Sculptor matriz3D(10, 10, 10);
  matriz3D.putBox(0, 2, 0, 2, 0, 2);
  matriz3D.setColor(1.0, 0, 0, 1.0);
  matriz3D.putSphere(5, 5, 5, 3);
  matriz3D.writeOFF("arquivo.off");
}