#include "include/wfc_trie.h"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

using namespace freq;
using namespace std;

WFC_Trie::WFC_Trie() {}

WFC_Trie::~WFC_Trie() {}

void WFC_Trie::countWordFrequence(const string &input,
                                  vector<pair<string, size_t>> &result) {

  vector<Node> trie(1);
  uint_fast32_t nodeIndex = 0;

  auto addCharacter = [&](char const &c) {
    if (isalpha(c)) {
      uint32_t &charIndex = trie[nodeIndex].nodes[c - 'a'];
      if (charIndex == 0) {
        nodeIndex = uint32_t(trie.size());
        charIndex = nodeIndex;
        trie.emplace_back();
      } else {
        nodeIndex = charIndex;
      }
    } else if (nodeIndex != 0) {
      ++trie[nodeIndex].cnt;
      nodeIndex = 0;
    }
  };
  for_each(input.cbegin(), input.cend(), addCharacter);

  vector<pair<uint32_t, uint32_t>> order;
  vector<string> words;
  string word;

  auto collect = [&](const auto collect, const auto &nodes) -> void {
    size_t step = 0;
    for (auto node : nodes) {
      if (node != 0) {
        const Node &tmp_node = trie[node];
        word.push_back('a' + step);
        if (tmp_node.cnt != 0) {
          order.emplace_back(tmp_node.cnt, uint32_t(words.size()));
          words.push_back(word);
        }
        collect(collect, tmp_node.nodes);
        word.pop_back();
      }
      ++step;
    }
  };

  collect(collect, trie.front().nodes);

  stable_sort(std::begin(order), std::end(order),
              [](auto &&l, auto &&r) { return r.first < l.first; });

  for (auto &[count, word] : order) {
    pair<string, size_t> line = make_pair(words[word], count);
    result.push_back(line);
  }
}
