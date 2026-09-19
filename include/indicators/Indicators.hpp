#pragma once
#include "data/MarketData.hpp"
#include <vector>
namespace qte::indicators {
std::vector<double> sma(const std::vector<double>& x, std::size_t period);
std::vector<double> ema(const std::vector<double>& x, std::size_t period);
std::vector<double> rsi(const std::vector<double>& x, std::size_t period);
std::vector<double> simpleReturns(const std::vector<double>& x);
std::vector<double> logReturns(const std::vector<double>& x);
std::vector<double> volatility(const std::vector<double>& x, std::size_t period);
std::vector<double> closes(const std::vector<Bar>& bars);
}
