# Strategies

Momentum compares fast and slow rolling SMAs. Mean reversion trades a rolling close z-score. Pairs trading computes `spread = asset_a - hedge_ratio * asset_b`, then standardizes it over a rolling window. A negative z-score indicates a long-spread signal and a positive score indicates a short-spread signal. Hedge ratio is configurable and should be estimated only from training data in serious research.

All strategies are signal generators, not profit claims. Parameters should be selected on training data and evaluated out of sample.
