#include "putellipsoid.h"
#include <cmath>
#include <iostream>
PutEllipsoid::PutEllipsoid() {}

PutEllipsoid::~PutEllipsoid() {}

void PutEllipsoid::draw(Sculptor &t) {
  for (int i = 0; i < t.getNx(); i++)
    for (int j = 0; j < t.getNy(); j++)
      for (int k = 0; k < t.getNz(); k++)
        if (std::pow(i - xcenter, 2) / std::pow(raiox, 2) +
                std::pow(j - ycenter, 2) / std::pow(raioy, 2) +
                std::pow(k - zcenter, 2) / std::pow(raioz, 2) <=
            1) {
          t.setColor(r, g, b, a);
          t.putVoxel(i, j, k);
        }
}

PutEllipsoid::PutEllipsoid(std::vector<std::string> v) {
  xcenter = std::stoi(v[1]);
  ycenter = std::stoi(v[2]);
  zcenter = std::stoi(v[3]);
  raiox = std::stoi(v[4]);
  raioy = std::stoi(v[5]);
  raioz = std::stoi(v[6]);

  r = std::stof(v[5]);
  g = std::stof(v[6]);
  b = std::stof(v[7]);
  a = std::stof(v[8]);
}