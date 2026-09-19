#pragma once
#include <cstddef>
namespace qte::execution { enum class Side { Buy, Sell }; struct Order { Side side; double quantity; }; struct Fill { Side side; double quantity{}, marketPrice{}, executionPrice{}, commission{}, slippage{}; }; class TransactionCostModel { public: TransactionCostModel(double commission=0.0005,double slippage=0.0002):commission_(commission),slippage_(slippage){} Fill fill(const Order&,double) const; private: double commission_,slippage_; }; }
