#include <gtest/gtest.h>
#include "portfolio/Portfolio.hpp"
using namespace qte;
TEST(Portfolio,AppliesFill){portfolio::Portfolio p(1000);execution::TransactionCostModel c(0,0);p.apply(1,"X",c.fill({execution::Side::Buy,2},100));EXPECT_DOUBLE_EQ(p.cash(),800);EXPECT_DOUBLE_EQ(p.equity(110),1020);}
