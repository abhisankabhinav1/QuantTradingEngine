# Data and execution contract

Signals generated after bar *t* are queued and filled at the open of bar *t+1*. This is the central look-ahead protection. OHLC validation rejects non-finite values, non-positive prices, invalid high/low relationships, negative volume, duplicate timestamps, and out-of-order data.

The portfolio uses signed quantity, average entry price, cash accounting, commission, directional slippage, and a ledger. The current single-asset backtester limits notional using `maxPositionFraction`; independent multi-asset pairs are represented by `PairsTradingStrategy`, while a future portfolio release should execute both legs atomically.
