#include "lib/include/wfc_trie.h"
#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char **argv) {
  if (argc < 3)
    return 0;

  std::fstream inputStream(argv[1]);
  if (!inputStream.is_open()) {
    return 0;
  }

  std::string input;
  if (std::ifstream is{argv[1], std::ios::binary | std::ios::ate}) {
    auto size = is.tellg();
    input.resize(size);
    is.seekg(0);
    is.read(&input[0], size);
  } else {
    return 0;
  }

  std::transform(std::cbegin(input), std::cend(input), std::begin(input),
                 [](unsigned char c) { return std::tolower(c); });

  freq::WFC_Trie wfc;
  std::vector<std::pair<std::string, std::size_t>> result;
  wfc.countWordFrequence(input, result);

  std::ofstream outStream(argv[2]);
  if (!outStream.is_open())
    return 0;
  for (auto line : result) {
    outStream << line.second << " " << line.first << "\n";
  }
  outStream.close();

  return 0;
}
