#include "cutellipsoid.h"
#include <cmath>
#include <iostream>

CutEllipsoid::CutEllipsoid() {}

CutEllipsoid::~CutEllipsoid() {}

void CutEllipsoid::draw(Sculptor &t) {
  for (int i = 0; i < t.getNx(); i++)
    for (int j = 0; j < t.getNy(); j++)
      for (int k = 0; k < t.getNz(); k++)
        if (std::pow(i - xcenter, 2) / std::pow(raiox, 2) +
                std::pow(j - ycenter, 2) / std::pow(raioy, 2) +
                std::pow(k - zcenter, 2) / std::pow(raioz, 2) <=
            1)
          t.cutVoxel(i, j, k);
}

CutEllipsoid::CutEllipsoid(std::vector<std::string> v) {
  xcenter = std::stoi(v[1]);
  ycenter = std::stoi(v[2]);
  zcenter = std::stoi(v[3]);
  raiox = std::stoi(v[4]);
  raioy = std::stoi(v[5]);
  raioz = std::stoi(v[6]);
}