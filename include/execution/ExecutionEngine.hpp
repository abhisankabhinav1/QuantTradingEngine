#pragma once
#include "Order.hpp"
namespace qte::execution { class ExecutionEngine { public: explicit ExecutionEngine(TransactionCostModel c={}):costs_(c){} Fill execute(const Order&o,double p) const{return costs_.fill(o,p);} private: TransactionCostModel costs_; }; }
