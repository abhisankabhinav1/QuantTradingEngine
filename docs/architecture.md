# Architecture

The library separates data validation, pure indicator functions, strategy decisions, execution simulation, and performance analysis. Most indicator routines use contiguous `std::vector<double>` storage. Rolling SMA is O(n) time and O(n) output space; EMA and RSI are O(n); the simple demo strategy currently recomputes indicator vectors per signal and is intentionally readable, making it a candidate for future caching optimization.

The backtester is deliberately single-threaded because cash and positions are stateful. Independent strategy runs can be parallelized later, but shared portfolio mutation must remain synchronized or serialized.
