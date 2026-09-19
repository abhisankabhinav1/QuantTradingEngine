#pragma once
#include <algorithm>
#include <cmath>
#include <vector>
namespace qte::risk {
inline double maxDrawdown(const std::vector<double>& equity) {
  double peak=0.0, result=0.0;
  for (double value: equity) { if (!std::isfinite(value)) continue; peak=std::max(peak,value); if (peak>0) result=std::min(result,value/peak-1.0); }
  return result;
}
}
