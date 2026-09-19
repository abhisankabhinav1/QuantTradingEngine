#pragma once
#include "data/MarketData.hpp"
#include <string>
#include <vector>
namespace qte {
enum class Signal { Hold, Buy, Sell };
class Strategy { public: virtual ~Strategy()=default; virtual Signal generateSignal(const std::vector<Bar>&,std::size_t) const=0; virtual std::string name() const=0; };
class MomentumStrategy final: public Strategy { std::size_t fast_,slow_; public: MomentumStrategy(std::size_t fast=10,std::size_t slow=30); Signal generateSignal(const std::vector<Bar>&,std::size_t) const override; std::string name() const override{return "Momentum";} };
class MeanReversionStrategy final: public Strategy { std::size_t period_; double threshold_; public: MeanReversionStrategy(std::size_t period=20,double threshold=2.0); Signal generateSignal(const std::vector<Bar>&,std::size_t) const override; std::string name() const override{return "MeanReversion";} };
class PairsTradingStrategy { public: enum class PairSignal { Flat, LongSpread, ShortSpread }; PairsTradingStrategy(std::size_t period=20,double hedgeRatio=1.0,double threshold=2.0); PairSignal generateSignal(const std::vector<Bar>& first,const std::vector<Bar>& second,std::size_t index) const; double zScore(const std::vector<Bar>&,const std::vector<Bar>&,std::size_t) const; private: std::size_t period_; double hedgeRatio_,threshold_; };
}
