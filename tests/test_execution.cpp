#include <gtest/gtest.h>
#include "execution/ExecutionEngine.hpp"
using namespace qte;
TEST(Execution,DirectionalSlippage){execution::TransactionCostModel c(0,.01);auto b=c.fill({execution::Side::Buy,1},100);auto s=c.fill({execution::Side::Sell,1},100);EXPECT_GT(b.executionPrice,100);EXPECT_LT(s.executionPrice,100);EXPECT_DOUBLE_EQ(b.slippage,1);}
