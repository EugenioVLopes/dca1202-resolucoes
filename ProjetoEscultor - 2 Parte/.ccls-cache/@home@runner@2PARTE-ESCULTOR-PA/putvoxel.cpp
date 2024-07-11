#include "putvoxel.h"
#include <iostream>
#include <string>
#include <vector>

PutVoxel::PutVoxel() {}
PutVoxel::~PutVoxel() {}

PutVoxel::PutVoxel(std::vector<std::string> v) {
  x = std::stoi(v[1]);
  y = std::stoi(v[2]);
  z = std::stoi(v[3]);

  r = std::stof(v[4]);
  g = std::stof(v[5]);
  b = std::stof(v[6]);
  a = std::stof(v[7]);
}
void PutVoxel::draw(Sculptor &t) {
  t.setColor(r, g, b, a);
  t.putVoxel(x, y, z);
}