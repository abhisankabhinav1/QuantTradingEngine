#include <gtest/gtest.h>
#include "strategy/Strategy.hpp"
using namespace qte;
TEST(Strategy,DoesNotSignalBeforeWarmup){std::vector<Bar>b;for(int i=0;i<20;++i)b.push_back({i,100+i,101+i,99+i,100+i,1});MomentumStrategy s(3,5);EXPECT_EQ(s.generateSignal(b,3),Signal::Hold);}
TEST(Pairs,SpreadZScore){std::vector<Bar>a,b;for(int i=0;i<30;++i){a.push_back({i,100+i,101+i,99+i,100+i,1});b.push_back({i,50+i/2.0,51+i/2.0,49+i/2.0,50+i/2.0,1});}PairsTradingStrategy s(10,2,2);EXPECT_FALSE(std::isnan(s.zScore(a,b,29)));}
