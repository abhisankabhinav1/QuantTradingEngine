#pragma once
#include <cstddef>
#include <string>
#include <vector>
namespace qte::data {
struct Bar { long long timestamp{}; double open{}, high{}, low{}, close{}, volume{}; };
struct ValidationIssue { std::size_t index{}; std::string message; };
class DataValidator { public: static std::vector<ValidationIssue> validate(const std::vector<Bar>&); static void requireValid(const std::vector<Bar>&); };
class DataLoader { public: static std::vector<Bar> fromCsv(const std::string&); };
}
namespace qte { using data::Bar; using data::DataLoader; using data::DataValidator; }
