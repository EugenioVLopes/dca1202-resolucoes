#include "cutbox.h"
#include <iostream>
CutBox::CutBox() {}

CutBox::~CutBox() {}

void CutBox::draw(Sculptor &t)
{
  for (int i = x0; i < x1; i++)
    for (int j = y0; j < y1; j++)
      for (int k = z0; k < z1; k++)
        t.cutVoxel(i, j, k);
}

CutBox::CutBox(std::vector<std::string> v)
{
  x0 = std::stoi(v[1]);
  x1 = std::stoi(v[2]);
  y0 = std::stoi(v[3]);
  y1 = std::stoi(v[4]);
  z0 = std::stoi(v[5]);
  z1 = std::stoi(v[6]);
}