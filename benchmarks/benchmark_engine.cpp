#include <chrono>
#include <iostream>
#include <vector>
int main(){std::vector<double> data(1000000,1.0);auto t=std::chrono::steady_clock::now();double s=0;for(double x:data)s+=x;auto ms=std::chrono::duration<double>(std::chrono::steady_clock::now()-t).count();std::cout<<"rows="<<data.size()<<" rows_per_second="<<data.size()/ms<<" checksum="<<s<<"\n";}
