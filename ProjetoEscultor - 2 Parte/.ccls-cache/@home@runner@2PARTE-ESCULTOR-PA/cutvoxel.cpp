#include "cutvoxel.h"
#include "sculptor.h"
#include <iostream>
CutVoxel::CutVoxel() {}

CutVoxel::~CutVoxel() {}

void CutVoxel::draw(Sculptor &t) { t.cutVoxel(x, y, z); }

CutVoxel::CutVoxel(std::vector<std::string> v) {

  x = std::stoi(v[1]);
  y = std::stoi(v[2]);
  z = std::stoi(v[3]);
}