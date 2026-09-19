#include "backtest/BacktestEngine.hpp"
#include "performance/PerformanceAnalyzer.hpp"
#include <filesystem>
#include <iostream>
int main(){using namespace qte;std::vector<Bar>b;for(int i=0;i<500;++i){double p=100+i*.05+5*std::sin(i/20.0);b.push_back({i,p,p+1,p-1,p,1000});}BacktestConfig c;c.maxPositionFraction=.1;auto r=Backtester::run(b,MomentumStrategy{},c);std::filesystem::create_directories("results");PerformanceAnalyzer::writeEquity(r,"results/equity.csv");PerformanceAnalyzer::writeCsv(PerformanceAnalyzer::analyze(r,c.initialCapital,c.riskFreeRate),"results/summary.csv");std::cout<<"Final capital: "<<r.finalCapital<<"\n";}
