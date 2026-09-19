#include <gtest/gtest.h>
#include "backtest/BacktestEngine.hpp"
using namespace qte;
TEST(Backtest,ExecutionIsDelayed){std::vector<Bar>b={{1,10,10,10,10,1},{2,20,20,20,20,1},{3,20,20,20,20,1},{4,20,20,20,20,1}};class S:public Strategy{public:Signal generateSignal(const std::vector<Bar>&,size_t)const override{return Signal::Buy;}std::string name()const override{return "test";}};BacktestConfig c;c.commissionRate=0;c.slippageRate=0;c.maxPositionFraction=.1;auto r=Backtester::run(b,S{},c);EXPECT_EQ(r.trades.front().timestamp,2);EXPECT_DOUBLE_EQ(r.trades.front().price,20);}
TEST(Backtest,RejectsInvalid){EXPECT_THROW(Backtester::run({{1,0,1,1,1,1}},MomentumStrategy{},{}),std::invalid_argument);}
