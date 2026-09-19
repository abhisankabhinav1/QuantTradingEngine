#include "indicators/Indicators.hpp"
#include <chrono>
#include <iostream>
#include <vector>
int main(){using namespace qte;std::vector<double>x;for(int i=0;i<1000000;++i)x.push_back(100.0+i*.001);auto t=std::chrono::steady_clock::now();auto a=indicators::sma(x,50);auto b=indicators::ema(x,50);auto c=indicators::rsi(x,14);auto d=indicators::rollingVolatility(x,20);auto sec=std::chrono::duration<double>(std::chrono::steady_clock::now()-t).count();std::cout<<"dataset,sma_ema_rsi_volatility\nrows,"<<x.size()<<"\nseconds,"<<sec<<"\nrows_per_second,"<<x.size()/sec<<"\nchecksum,"<<a.back()+b.back()+c.back()+d.back()<<"\n";}
