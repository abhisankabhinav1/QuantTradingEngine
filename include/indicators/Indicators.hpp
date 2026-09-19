#pragma once
#include "data/MarketData.hpp"
#include <vector>
namespace qte::indicators {
std::vector<double> sma(const std::vector<double>&, std::size_t);
std::vector<double> ema(const std::vector<double>&, std::size_t);
std::vector<double> rsi(const std::vector<double>&, std::size_t);
std::vector<double> simpleReturns(const std::vector<double>&);
std::vector<double> logReturns(const std::vector<double>&);
std::vector<double> rollingVolatility(const std::vector<double>&, std::size_t, double periodsPerYear=252.0);
std::vector<double> closes(const std::vector<Bar>&);
}
