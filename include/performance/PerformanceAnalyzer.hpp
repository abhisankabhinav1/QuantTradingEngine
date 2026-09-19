#pragma once
#include "backtest/BacktestEngine.hpp"
#include <string>
namespace qte { struct Metrics { double totalReturn{}, cagr{}, annualVolatility{}, sharpe{}, sortino{}, maxDrawdown{}, calmar{}, winRate{}, profitFactor{}, averageTrade{}, turnover{}, totalFees{}, totalSlippage{}; std::size_t trades{}; };
class PerformanceAnalyzer { public: static Metrics analyze(const BacktestResult&, double initialCapital, double riskFreeRate=0.0); static void writeCsv(const Metrics&, const std::string&); static void writeEquity(const BacktestResult&, const std::string&); }; }
