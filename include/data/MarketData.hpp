#pragma once
#include <cstddef>
#include <string>
#include <vector>
namespace qte {
struct Bar { long long timestamp{}; double open{}, high{}, low{}, close{}, volume{}; };
class DataValidator { public: static std::vector<std::string> validate(const std::vector<Bar>& bars); static void requireValid(const std::vector<Bar>& bars); };
class DataLoader { public: static std::vector<Bar> fromCsv(const std::string& path); };
}
