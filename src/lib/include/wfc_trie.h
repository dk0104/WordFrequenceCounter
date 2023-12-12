#include <cstdint>
#include <vector>
#include <string>

namespace freq {

constexpr std::size_t ALPHABET = 'z' - 'a' + 1;

struct Node {
  uint32_t cnt = 0;
  uint32_t nodes[ALPHABET]={};
};

class WFC_Trie {
public:
  WFC_Trie();
  WFC_Trie(WFC_Trie &&) = default;
  WFC_Trie(const WFC_Trie &) = default;
  WFC_Trie &operator=(WFC_Trie &&) = default;
  WFC_Trie &operator=(const WFC_Trie &) = default;
  ~WFC_Trie();

  void countWordFrequence(
      const std::string &input,
      std::vector<std::pair<std::string, std::size_t>> &result);
};
} // namespace freq
