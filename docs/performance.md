# Benchmarking

The benchmark is a reproducible throughput harness rather than a trading claim. It measures indicator pipeline wall time for four data sizes and writes `rows,seconds,rows_per_second,checksum` to CSV plus equivalent JSON. Run it on an otherwise idle machine and publish compiler, flags, CPU, operating system, and memory details with any result.
