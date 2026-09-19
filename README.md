# QuantTradingEngine

A C++20 quantitative research and bar-by-bar backtesting engine with Python analysis tools. This is an educational engineering project: results are experimental backtests, not investment advice or evidence of future profitability.

## Features

- Validated OHLCV market data and CSV loading
- O(n) rolling SMA, EMA, RSI, returns, and volatility indicators
- Momentum and mean-reversion strategies with no look-ahead execution
- Configurable commission and slippage
- Cash, positions, trade ledger, exposure, and equity curve
- Return, CAGR, volatility, Sharpe, Sortino, drawdown, win-rate, and profit-factor metrics
- CMake build, optional GoogleTest tests, and Python plotting/reporting scripts

## Architecture

```text
CSV -> DataLoader/Validator -> Indicators -> Strategy -> Risk -> Execution
                                      -> Portfolio -> Performance -> Report
```

A signal computed from bar *t* is queued and executed at the open of bar *t+1*. This deliberate one-bar delay prevents using information that was unavailable at decision time.

## Build and run

```bash
sudo apt install cmake g++ libgtest-dev python3-pip
cmake -S . -B build -DQTE_BUILD_TESTS=ON
cmake --build build -j
./build/qte_demo
ctest --test-dir build --output-on-failure
```

The demo creates a deterministic synthetic series and writes `results/equity.csv` and `results/summary.csv`. For real research, prepare a CSV with columns `timestamp,open,high,low,close,volume` and replace the demo data only after validating its provenance.

## Python analysis

```bash
pip install -r python/requirements.txt
python3 python/analyze_results.py results/equity.csv
```

## Mathematics

SMA is the rolling arithmetic mean. EMA uses `EMA_t = alpha*x_t + (1-alpha)*EMA_(t-1)`, where `alpha=2/(N+1)`. Returns are `P_t/P_(t-1)-1`; annualized volatility is the standard deviation of returns times `sqrt(252)`. Sharpe is annualized mean excess return divided by annualized volatility. Drawdown is equity divided by its previous running peak minus one.

## Limitations and roadmap

This engine uses bar data, simplified market orders, fixed proportional costs, no market impact, and single-asset examples. It does not model order-book liquidity, corporate actions, survivorship bias, regime changes, or live trading. Future work includes multi-asset portfolios, event-driven execution, limit-order books, walk-forward validation, parallel strategy evaluation, and profiling.

See `docs/` for design notes. Never treat a historical backtest as a guarantee of returns.
