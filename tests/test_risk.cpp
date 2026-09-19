#include <gtest/gtest.h>
#include "risk/RiskManager.hpp"
using namespace qte;
TEST(Risk,ExposureGate){risk::RiskManager r({.1,.5,.2, .1});EXPECT_FALSE(r.allowsNewPosition(100,60,100));EXPECT_TRUE(r.allowsNewPosition(100,40,100));EXPECT_FALSE(r.allowsNewPosition(70,1,100));}
TEST(Risk,Sizing){EXPECT_GT(risk::PositionSizer::volatilityTarget(100000,.01,.2,100),0);}
