#include <vector>
#include <string>


namespace freq {
class WFC_Map {
public:
  WFC_Map();
  WFC_Map(WFC_Map &&) = default;
  WFC_Map(const WFC_Map &) = default;
  WFC_Map &operator=(WFC_Map &&) = default;
  WFC_Map &operator=(const WFC_Map &) = default;
  ~WFC_Map();
  
  void countWordFrequence(
      const std::string &input,
      std::vector<std::pair<std::string, std::size_t>> &result);
};
} // namespace freq
