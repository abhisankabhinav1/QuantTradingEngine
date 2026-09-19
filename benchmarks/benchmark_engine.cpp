#include "indicators/Indicators.hpp"
#include <chrono>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace {
struct Measurement { std::size_t rows{}; double seconds{}; double rowsPerSecond{}; double checksum{}; };
Measurement run(std::size_t n) {
  std::vector<double> prices; prices.reserve(n);
  for (std::size_t i=0;i<n;++i) prices.push_back(100.0 + 0.001*static_cast<double>(i) + std::sin(i/100.0));
  const auto start=std::chrono::steady_clock::now();
  const auto sma=qte::indicators::sma(prices,50);
  const auto ema=qte::indicators::ema(prices,50);
  const auto rsi=qte::indicators::rsi(prices,14);
  const auto vol=qte::indicators::rollingVolatility(prices,20);
  const double seconds=std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count();
  const double checksum=sma.back()+ema.back()+rsi.back()+vol.back();
  return {n,seconds,static_cast<double>(n)/seconds,checksum};
}
}
int main(int argc,char** argv) {
  const std::string out=argc>1?argv[1]:"results/benchmark.csv";
  std::filesystem::path path(out); if (path.has_parent_path()) std::filesystem::create_directories(path.parent_path());
  const std::vector<std::size_t> sizes={10000,100000,1000000,10000000};
  std::ofstream csv(out); if(!csv) { std::cerr<<"cannot open "<<out<<'\n'; return 1; }
  csv<<"rows,seconds,rows_per_second,checksum\n";
  std::ofstream json(path.replace_extension(".json"));
  json<<"{\n  \"benchmark\": \"indicator_pipeline\",\n  \"measurements\": [\n";
  for(std::size_t i=0;i<sizes.size();++i){auto m=run(sizes[i]);csv<<m.rows<<','<<std::setprecision(12)<<m.seconds<<','<<m.rowsPerSecond<<','<<m.checksum<<'\n';json<<"    {\"rows\": "<<m.rows<<", \"seconds\": "<<m.seconds<<", \"rows_per_second\": "<<m.rowsPerSecond<<", \"checksum\": "<<m.checksum<<"}"<<(i+1<sizes.size()?",":"")<<"\n";std::cout<<m.rows<<" rows: "<<m.rowsPerSecond<<" rows/s\n";}
  json<<"  ]\n}\n";
}
