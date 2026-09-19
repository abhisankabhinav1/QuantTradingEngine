# Strategies

Momentum compares fast and slow simple moving averages. Mean reversion computes a rolling z-score and trades only when it exceeds a configurable threshold. Both use only bars at or before the signal bar; orders execute on the next bar's open. Pairs trading is not included in this first build because a correct multi-asset data model and hedge-ratio estimation should be added rather than represented by a misleading stub.
