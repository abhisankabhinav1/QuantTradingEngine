#pragma once
#include "strategy/Strategy.hpp"
namespace qte {
struct BacktestConfig { double initialCapital=100000.0, commissionRate=0.0005, slippageRate=0.0002, riskFreeRate=0.0, maxPositionFraction=1.0; std::size_t maxBars=0; };
struct Trade { long long timestamp{}; Signal side{Signal::Hold}; double quantity{}, price{}, fees{}, slippage{}, realizedPnl{}; };
struct BacktestResult { std::vector<double> equity; std::vector<Trade> trades; double finalCapital{}; };
class Backtester { public: static BacktestResult run(const std::vector<Bar>&, const Strategy&, const BacktestConfig&={}); };
}
