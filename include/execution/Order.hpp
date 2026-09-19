#pragma once
#include <cmath>
#include <cstddef>
#include <stdexcept>
namespace qte::execution {
enum class Side { Buy, Sell };
struct Order { Side side{}; double quantity{}; };
struct Fill { Side side{}; double quantity{}; double marketPrice{}; double executionPrice{}; double commission{}; double slippage{}; };
class TransactionCostModel {
public:
  TransactionCostModel(double commission=0.0005, double slippage=0.0002)
      : commission_(commission), slippage_(slippage) {
    if (!std::isfinite(commission) || commission < 0 || !std::isfinite(slippage) || slippage < 0)
      throw std::invalid_argument("transaction costs must be finite and non-negative");
  }
  Fill fill(const Order&, double marketPrice) const;
private:
  double commission_;
  double slippage_;
};
}
