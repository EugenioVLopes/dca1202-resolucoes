#include "putbox.h"
#include "sculptor.h"
#include <iostream>
#include <string>
#include <vector>
PutBox::PutBox() {}

PutBox::~PutBox() {}

void PutBox::draw(Sculptor &t) {
  for (int i = x; i < x1; i++)
    for (int j = y; j < y1; j++)
      for (int k = z; k < z1; k++) {
        t.setColor(r, g, b, a);
        t.putVoxel(i, j, k);
      }
}

PutBox::PutBox(std::vector<std::string> v) {
  x = std::stoi(v[1]);
  x1 = std::stoi(v[2]);
  y = std::stoi(v[3]);
  y1 = std::stoi(v[4]);
  z = std::stoi(v[5]);
  z1 = std::stoi(v[6]);
  r = std::stof(v[7]);
  g = std::stof(v[8]);
  b = std::stof(v[9]);
  a = std::stof(v[10]);
}