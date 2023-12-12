#include "include/wfc_map.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>

using namespace freq;
using namespace std;

WFC_Map::WFC_Map() {}

WFC_Map::~WFC_Map() {}

void WFC_Map::countWordFrequence(const string &input,
                                 vector<pair<string, size_t>> &result) {

  auto isAlpha = [](char c) { return isalpha(make_unsigned_t<char>(c)); };

  auto s_end = input.cend();
  auto s_begin = find_if(input.cbegin(), s_end, isAlpha);

  unordered_map<string, size_t> words;
  while (s_begin < s_end) {
    auto it = find_if_not(s_begin, s_end, isAlpha);
    ++words[{s_begin, it}];
    s_begin = find_if(it, s_end, isAlpha);
  }

  result.reserve(words.size());

  for (const auto &word : words) {
    result.push_back(word);
  }

  auto d_sort = [](auto lhs, auto rhs) -> bool {
    return tie(rhs.second, lhs.first) < tie(lhs.second, rhs.first);
  };

  sort(begin(result), end(result), d_sort);
}
