#include "data/MarketData.hpp"
#include "strategy/Strategy.hpp"
#include "backtest/BacktestEngine.hpp"
#include "performance/PerformanceAnalyzer.hpp"
#include <filesystem>
#include <iostream>
int main(){using namespace qte;std::vector<Bar>b;for(int i=0;i<500;++i){double p=100+i*0.05+5*std::sin(i/20.0);b.push_back({i,p,p+1,p-1,p,1000});}BacktestConfig c;c.initialCapital=100000;c.maxPositionFraction=.95;auto r=Backtester::run(b,MomentumStrategy(10,30),c);std::filesystem::create_directories("results");auto m=PerformanceAnalyzer::analyze(r,c.initialCapital,c.riskFreeRate);PerformanceAnalyzer::writeEquity(r,"results/equity.csv");PerformanceAnalyzer::writeCsv(m,"results/summary.csv");std::cout<<"Final capital: "<<r.finalCapital<<" trades: "<<m.trades<<"\n";}
