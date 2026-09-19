#include <gtest/gtest.h>
#include "indicators/Indicators.hpp"
using namespace qte;
TEST(SMA,Rolling){auto x=indicators::sma({1,2,3,4},2);EXPECT_TRUE(std::isnan(x[0]));EXPECT_DOUBLE_EQ(x[3],3.5);}
TEST(EMA,Seeded){auto x=indicators::ema({1,2,3,4},2);EXPECT_DOUBLE_EQ(x[1],1.5);}
TEST(RSI,Range){auto x=indicators::rsi({1,2,3,2,3,4},3);EXPECT_GE(x.back(),0);EXPECT_LE(x.back(),100);}
