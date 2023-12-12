#include <cstddef>
#include <string>
#include <vector>

struct TextTestChunk {
  TextTestChunk(const std::string input,
                std::vector<std::pair<std::string, std::size_t>> result)
      : inputString(input), resultMap(result) {}
  std::string inputString;
  std::vector<std::pair<std::string, std::size_t>> resultMap;
};

typedef TextTestChunk *TestInput[];


