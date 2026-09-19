# Performance and benchmarks

Trading metrics include total return, CAGR, annualized volatility, Sharpe, Sortino, maximum drawdown, Calmar, win rate, profit factor, trade count, fees, and slippage. A zero denominator produces a neutral metric rather than infinity.

`qte_benchmark` measures indicator throughput with `std::chrono`, reports rows/second, and prints a checksum to prevent dead-code elimination. Repeat it for 10k, 100k, 1m, and 10m rows and record compiler, CPU, optimization flags, wall time, and memory separately. These are software measurements, not trading performance.
