#include <gtest/gtest.h>
#include "data/MarketData.hpp"
#include "indicators/Indicators.hpp"
#include "backtest/BacktestEngine.hpp"
using namespace qte;
TEST(Indicators,SMA){auto x=indicators::sma({1,2,3,4},2);EXPECT_TRUE(std::isnan(x[0]));EXPECT_DOUBLE_EQ(x[3],3.5);}
TEST(Indicators,Returns){auto x=indicators::simpleReturns({100,110});EXPECT_DOUBLE_EQ(x[1],.1);}
TEST(Data,RejectsBadBar){EXPECT_THROW(DataValidator::requireValid({{1,1,0,1,1,1}}),std::invalid_argument);}
TEST(Backtest,NoLookAhead){std::vector<Bar>b;for(int i=0;i<4;++i)b.push_back({i,10+i,10+i,10+i,10+i,1});BacktestConfig c;c.initialCapital=1000;auto r=Backtester::run(b,MomentumStrategy(2,3),c);EXPECT_EQ(r.equity.size(),4u);}
