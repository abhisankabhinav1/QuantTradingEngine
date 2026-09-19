#pragma once
#include "data/MarketData.hpp"
#include "indicators/Indicators.hpp"
#include <memory>
namespace qte {
enum class Signal { Hold, Buy, Sell };
class Strategy { public: virtual ~Strategy()=default; virtual Signal signal(const std::vector<Bar>& bars, std::size_t i) const=0; virtual std::string name() const=0; };
class MomentumStrategy final: public Strategy { std::size_t fast_, slow_; public: MomentumStrategy(std::size_t fast=10,std::size_t slow=30):fast_(fast),slow_(slow){} Signal signal(const std::vector<Bar>&,std::size_t) const override; std::string name() const override{return "Momentum";} };
class MeanReversionStrategy final: public Strategy { std::size_t period_; double threshold_; public: MeanReversionStrategy(std::size_t p=20,double z=2):period_(p),threshold_(z){} Signal signal(const std::vector<Bar>&,std::size_t) const override; std::string name() const override{return "MeanReversion";} };
}
