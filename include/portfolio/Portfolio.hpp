#pragma once
#include "Position.hpp"
#include "execution/Order.hpp"
#include <string>
#include <unordered_map>
#include <vector>
namespace qte::portfolio {
struct LedgerEntry { long long timestamp{}; std::string symbol; execution::Side side{}; double quantity{},price{},fees{},slippage{},realizedPnl{}; };
class Portfolio {
public:
  explicit Portfolio(double cash): cash_(cash) {}
  void apply(long long, const std::string&, const execution::Fill&);
  double equity(double price) const;
  double cash() const noexcept { return cash_; }
  double quantity(const std::string& symbol="DEFAULT") const;
  const std::vector<LedgerEntry>& ledger() const noexcept { return ledger_; }
private:
  double cash_;
  std::unordered_map<std::string,Position> positions_;
  std::vector<LedgerEntry> ledger_;
};
}
