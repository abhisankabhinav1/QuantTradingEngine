#pragma once
#include "Portfolio.hpp"
namespace qte::portfolio { class PortfolioManager { public: explicit PortfolioManager(double initial):portfolio_(initial){} Portfolio& portfolio(){return portfolio_;} private: Portfolio portfolio_; }; }
