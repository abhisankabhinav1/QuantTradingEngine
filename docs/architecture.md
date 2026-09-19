# Architecture and build boundaries

The API is intentionally split into data, indicators, strategy, execution, portfolio, risk, backtest, and performance namespaces. `src/engine.cpp` is currently the library's portable implementation boundary so that consumers build one small static target; the empty domain source files identify the seams for a future translation-unit split without changing the public API.

The stateful components are deliberately ordered: a strategy creates a signal, risk approves a proposed notional, execution creates a fill, and the portfolio applies that fill. The backtester is single-threaded because cash and positions are mutable state. Independent strategy runs can be parallelized, but fills on one portfolio cannot be concurrently mutated without a defined event-ordering model.

Configure with `QTE_ENABLE_SANITIZERS=ON` during development. Build warnings are enabled for GCC and Clang.
