#include "putsphere.h"
#include <cmath>
#include <iostream>

PutSphere::PutSphere() {}

PutSphere::~PutSphere() {}

void PutSphere::draw(Sculptor &t) {
  // equação (x - x0)^2 + (y - y0)^2 + (z - z0)^2 = r^2

  for (int i = 0; i < t.getNx(); i++)
    for (int j = 0; j < t.getNy(); j++)
      for (int k = 0; k < t.getNz(); k++)
        if ((float)(std::pow(i - xcenter, 2) + std::pow(j - ycenter, 2) +
                    std::pow(k - zcenter, 2)) <= (float)std::pow(radius, 2)) {
          t.setColor(r, g, b, a);
          t.putVoxel(i, j, k);
        }
}

PutSphere::PutSphere(std::vector<std::string> v) {
  xcenter = std::stoi(v[1]);
  ycenter = std::stoi(v[2]);
  zcenter = std::stoi(v[3]);
  radius = std::stoi(v[4]);
  r = std::stof(v[5]);
  g = std::stof(v[6]);
  b = std::stof(v[7]);
  a = std::stof(v[8]);
}