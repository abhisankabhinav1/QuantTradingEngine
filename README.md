# QuantTradingEngine

QuantTradingEngine is a C++20 educational quantitative research and backtesting system with Python analysis. It is designed to make data structures, numerical methods, execution assumptions, risk controls, testing, and performance engineering visible in a portfolio project. It does not claim alpha, profitability, or institutional realism.

## Repository layout

```text
include/{data,indicators,strategy,execution,portfolio,risk,backtest,performance}
src/{data,indicators,strategy,execution,portfolio,risk,backtest,performance}/
tests/  python/  benchmarks/  docs/  data/sample/  results/
```

The public API is organized by domain. The current implementation keeps the library build simple in one translation unit while exposing separable headers; the next refactoring step is to move each domain implementation into its matching `src/` directory.

## Build

```bash
cmake -S . -B build -DQTE_BUILD_TESTS=ON -DQTE_BUILD_BENCHMARKS=ON
cmake --build build -j
ctest --test-dir build --output-on-failure
./build/qte_demo
./build/qte_benchmark
```

GoogleTest is optional at configure time. Install it through the platform package manager or use a FetchContent policy suitable for your environment.

## Data contract

CSV format is `timestamp,open,high,low,close,volume`. Timestamps must be strictly increasing. Prices must be finite and positive; high must be at least open and close; low must be at most open and close; volume cannot be negative. Invalid data fails loudly.

## Research model

The engine uses bar-close signals and next-bar-open fills. Buys pay positive slippage, sells receive a lower execution price, and commissions are proportional to notional. The portfolio tracks cash, signed positions, average price, realized P&L, and a trade ledger. `maxPositionFraction` and drawdown/exposure gates prevent unbounded simulated positions.

## Indicators and complexity

SMA uses a rolling sum: O(n) time and O(n) output space. EMA is O(n) with a seeded SMA. RSI uses Wilder-style smoothed average gains/losses in O(n). Volatility uses sample standard deviation of rolling simple returns and annualizes by sqrt(252). NaN warm-up values are intentional and prevent pretending an indicator exists before enough observations.

## Strategies

- Momentum: fast SMA versus slow SMA.
- Mean reversion: configurable rolling z-score threshold.
- Pairs: spread and hedge-ratio z-score over two synchronized series. It is a signal component; atomic two-leg execution is a planned extension.

## Python analysis

```bash
python3 -m pip install -r python/requirements.txt
python3 python/analyze_results.py results/equity.csv
```

The script saves equity and drawdown plots in `results/plots/` and does not manufacture performance numbers.

## Limitations and responsible interpretation

This is not live trading software. It omits market impact, order-book liquidity, partial fills, corporate actions, calendar alignment, borrow costs, financing, survivorship bias controls, and robust walk-forward evaluation. Historical backtests are sensitive to data quality, costs, parameter overfitting, and regime changes. Label all outputs **Backtest / Experimental Results** and never infer future returns from them.

## Roadmap

Split the implementation into domain translation units; add multi-symbol synchronized data; implement atomic pairs execution; add stop-loss and volatility targeting to the backtester; add JSON configuration; add walk-forward validation; add memory benchmarks and optional parallel independent strategy runs; then consider an event-driven engine and limit-order book.
