#include "cutsphere.h"
#include <cmath>
#include <iostream>
CutSphere::CutSphere() {}

CutSphere::~CutSphere() {}

void CutSphere::draw(Sculptor &t) {
  for (int i = 0; i < t.getNx(); i++)
    for (int j = 0; j < t.getNy(); j++)
      for (int k = 0; k < t.getNz(); k++)
        if ((float)(std::pow(i - xcenter, 2) + std::pow(j - ycenter, 2) +
                    std::pow(k - zcenter, 2)) <= (float)std::pow(radius, 2))
          t.cutVoxel(i, j, k);
}

CutSphere::CutSphere(std::vector<std::string> v) {
  xcenter = std::stoi(v[1]);
  ycenter = std::stoi(v[2]);
  zcenter = std::stoi(v[3]);
  radius = std::stoi(v[4]);
}