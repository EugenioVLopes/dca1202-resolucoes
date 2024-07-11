#include "cutbox.h"
#include <iostream>
CutBox::CutBox() {}

CutBox::~CutBox() {}

void CutBox::draw(Sculptor &t) {
  for (int i = x; i < x1; i++)
    for (int j = y; j < y1; j++)
      for (int k = z; k < z1; k++)
        t.cutVoxel(i, j, k);
}

CutBox::CutBox(std::vector<std::string> v) {
  x = std::stoi(v[1]);
  x1 = std::stoi(v[2]);
  y = std::stoi(v[3]);
  y1 = std::stoi(v[4]);
  z = std::stoi(v[5]);
  z1 = std::stoi(v[6]);
}