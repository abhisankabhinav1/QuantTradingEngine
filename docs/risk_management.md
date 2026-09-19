# Risk management

The risk layer provides a maximum exposure gate, maximum drawdown gate, stop-loss helper, and volatility-targeted sizing formula. Risk checks are applied before simulated orders. Production extensions should make position limits symbol-aware, reserve cash for fees, support atomic multi-leg pairs orders, and test behavior during gaps and missing data.
