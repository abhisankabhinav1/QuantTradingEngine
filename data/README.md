# Data format

CSV files should contain a header and ISO-8601 or integer timestamps:

```csv
timestamp,open,high,low,close,volume
2024-01-01,100,102,99,101,1200
```

The validator rejects non-finite values, non-positive prices, negative volume, invalid OHLC relationships, and duplicate/non-monotonic timestamps. Do not commit proprietary or very large datasets.
