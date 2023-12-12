#include <benchmark/benchmark.h>

#include "wfc_map.h"
#include "wfc_trie.h"

static void BM_WFC_MAP(benchmark::State& state) {

  //auto wfcMapSolution = new freq::WFC_Map();
  freq::WFC_Map wfc_map;
  std::vector<std::pair<std::string, std::size_t>> result;
  for(auto _ : state)
  {
    wfc_map.countWordFrequence("the time has come, the walrus said",result);
  }
}

static void BM_WFC_TRIE(benchmark::State& state) {

  //auto wfcMapSolution = new freq::WFC_Map();
  freq::WFC_Trie wfc_trie;
  std::vector<std::pair<std::string, std::size_t>> result;
  for(auto _ : state)
  {
    wfc_trie.countWordFrequence("the time has come, the walrus said",result);
  }
}
BENCHMARK(BM_WFC_MAP);
BENCHMARK(BM_WFC_TRIE);
BENCHMARK_MAIN();
