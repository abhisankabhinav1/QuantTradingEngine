#pragma once
#include "Position.hpp"
#include "execution/Order.hpp"
#include <unordered_map>
#include <string>
namespace qte::portfolio { struct LedgerEntry { long long timestamp{}; std::string symbol; execution::Side side; double quantity{},price{},fees{},slippage{},realizedPnl{}; }; class Portfolio { public: explicit Portfolio(double cash):cash_(cash){} void apply(long long,const std::string&,const execution::Fill&); double equity(double) const; double cash() const{return cash_;} double quantity(const std::string&s="DEFAULT") const; const std::vector<LedgerEntry>& ledger() const{return ledger_;} private: double cash_; std::unordered_map<std::string,Position> positions_; std::vector<LedgerEntry> ledger_; }; }
