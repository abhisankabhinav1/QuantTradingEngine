#pragma once
#include <vector>
namespace qte::risk { inline double maxDrawdown(const std::vector<double>&e){double peak=0,result=0;for(double x:e){peak=std::max(peak,x);if(peak>0)result=std::min(result,x/peak-1);}return result;} }
