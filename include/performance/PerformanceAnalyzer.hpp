#pragma once
#include "backtest/BacktestEngine.hpp"
#include <string>
namespace qte { struct PerformanceMetrics {double totalReturn{},cagr{},annualizedVolatility{},sharpe{},sortino{},maximumDrawdown{},calmar{},winRate{},profitFactor{},averageTrade{},turnover{},totalFees{},totalSlippage{};std::size_t numberOfTrades{};}; class PerformanceAnalyzer {public: static PerformanceMetrics analyze(const BacktestResult&,double,double=0); static void writeEquity(const BacktestResult&,const std::string&); static void writeCsv(const PerformanceMetrics&,const std::string&);}; using Metrics=PerformanceMetrics; }
