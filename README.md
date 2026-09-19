# QuantTradingEngine

> **Educational quantitative research and backtesting engine in C++20, with Python analysis.**

[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue)](https://en.cppreference.com/w/cpp/20) [![CMake](https://img.shields.io/badge/build-CMake%203.20+-064F8C)](https://cmake.org/) [![Research](https://img.shields.io/badge/use-research%20only-orange)](#responsible-use)

QuantTradingEngine is a portfolio project for learning systems programming, numerical algorithms, quantitative finance, testing, and performance measurement. The primary backtesting loop is C++; Python is used only for analysis and visualization. It makes no claim of alpha, profitability, or institutional readiness.

## Highlights

- Validated OHLCV CSV ingestion with fail-fast errors
- O(n) SMA, seeded EMA, Wilder RSI, returns, and rolling sample volatility
- Momentum, mean-reversion, and synchronized two-asset pairs signals
- Next-bar-open execution to make look-ahead assumptions explicit
- Directional slippage, proportional commissions, cash, average cost, realized P&L, and ledger
- Exposure and drawdown gates plus volatility-aware position-sizing helper
- GoogleTest coverage for indicators, costs, portfolio accounting, risk, and look-ahead behavior
- Benchmark executable producing CSV and JSON for 10k–10m rows

## Architecture

```text
MarketData -> Validation -> Indicators -> Strategy -> Risk gate
                                                   -> Order -> Execution
                                                   -> Portfolio -> Metrics -> CSV/Python plots
```

The public headers are separated by domain under `include/`. The current static library uses a single compiled implementation unit for a simple, portable build; the matching `src/<domain>/` files document the intended seams and are ready for further translation-unit extraction.

## Build from source

```bash
git clone https://github.com/abhisankabhinav1/QuantTradingEngine.git
cd QuantTradingEngine
cmake -S . -B build -DQTE_BUILD_TESTS=ON -DQTE_BUILD_BENCHMARKS=ON
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

Optional safety checks with GCC/Clang:

```bash
cmake -S . -B build-sanitize -DQTE_ENABLE_SANITIZERS=ON
cmake --build build-sanitize --parallel
```

GoogleTest is optional. If it is not installed, the demo and benchmark still build and CMake reports that tests were skipped.

## Run

```bash
./build/qte_demo
./build/qte_benchmark results/benchmark.csv
python3 -m pip install -r python/requirements.txt
python3 python/analyze_results.py results/equity.csv
```

The demo writes `results/equity.csv` and `results/summary.csv`. The benchmark writes both the requested CSV and a same-name `.json` file. Generated outputs are ignored by Git.

## Data contract

```csv
timestamp,open,high,low,close,volume
1704067200,100,102,99,101,1200
```

Timestamps must be strictly increasing. Prices must be finite and positive; `high >= max(open, close)`, `low <= min(open, close)`, and volume must be non-negative. Invalid records are rejected rather than silently dropped.

## Execution and look-ahead policy

A strategy observes bar *t* only after its close. The resulting signal is queued and, when possible, filled at bar *t+1* open. Buys pay positive slippage, sells receive a lower price, and commission is charged on notional. The tests include a custom strategy that verifies the first fill cannot occur on the signal bar.

## Quantitative methods

- **SMA:** rolling sum, O(n) time.
- **EMA:** SMA seed followed by `EMA_t = αP_t + (1-α)EMA_(t-1)`.
- **RSI:** Wilder-smoothed average gains and losses, bounded in [0,100].
- **Volatility:** sample standard deviation of simple returns, annualized by `sqrt(252)`.
- **Pairs:** `spread = A - hedge_ratio × B`, standardized over a rolling window. Hedge ratios should be estimated from training data, not the test period.

Warm-up observations are represented by NaN and must not be interpreted as signals.

## Benchmark methodology

`qte_benchmark` measures one indicator pipeline using `std::chrono`, reports rows/second, and emits a checksum to make accidental dead-code elimination detectable. It runs 10,000, 100,000, 1,000,000, and 10,000,000 rows. Record compiler version, CPU, optimization flags, wall time, and memory when publishing results. These are software measurements, not trading-performance results.

## Project layout

```text
include/{data,indicators,strategy,execution,portfolio,risk,backtest,performance}
src/{data,indicators,strategy,execution,portfolio,risk,backtest,performance}/
tests/  python/  benchmarks/  docs/  data/sample/  results/
```

## Responsible use and limitations

This is not live-trading software and is not financial advice. The model omits order-book liquidity, market impact, partial fills, borrow/financing costs, corporate actions, calendars, atomic two-leg pairs execution, and complete multi-symbol portfolio valuation. Backtests remain vulnerable to bad data, survivorship bias, overfitting, regime changes, and unrealistic cost assumptions. Historical results do not predict future returns. Label generated outputs **Backtest / Experimental Results**.

## Roadmap

1. Extract the library into independently compiled domain translation units.
2. Add synchronized multi-symbol portfolios and atomic pairs orders.
3. Add stop-loss execution, borrow fees, financing, and market-impact models.
4. Add walk-forward/out-of-sample evaluation and parameter provenance.
5. Add profiling, memory benchmarks, and optional parallel independent strategy runs.
6. Consider an event-driven simulator and simplified limit-order book.
