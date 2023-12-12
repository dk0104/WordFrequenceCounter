#include "TestChunks.h"
#include "wfc_trie.h"
#include <gtest/gtest.h>

using namespace std;
using namespace freq;

using ::testing::Bool;
using ::testing::Combine;
using ::testing::TestWithParam;
using ::testing::Values;
using ::testing::ValuesIn;

auto chunk_trie1 = new TextTestChunk(
    "wenn fliegen hinter fliegen fliegen, dann fliegen fliegen fliegen nach.",
    {{"fliegen", 6}, {"dann", 1}, {"hinter", 1}, {"nach", 1}, {"wenn", 1}});

auto chunk_trie2 = new TextTestChunk(
    "the time has come, the walrus said, to talk of many things.",
    {{"the", 2},
     {"come", 1},
     {"has", 1},
     {"many", 1},
     {"of", 1},
     {"said", 1},
     {"talk", 1},
     {"things", 1},
     {"time", 1},
     {"to", 1},
     {"walrus", 1}});
auto chunk_trie3 = new TextTestChunk("......------;;;;;:::::", {});
auto chunk_trie4 = new TextTestChunk(
    "the&time*has.come,the.walrus:said, to talk)of many things!",
    {{"the", 2},
     {"come", 1},
     {"has", 1},
     {"many", 1},
     {"of", 1},
     {"said", 1},
     {"talk", 1},
     {"things", 1},
     {"time", 1},
     {"to", 1},
     {"walrus", 1}});

TestInput positiveInput_trie{chunk_trie1, chunk_trie2,chunk_trie3,chunk_trie4};

class Test_WFC_Trie : public TestWithParam<TextTestChunk *> {
public:
  ~Test_WFC_Trie() {
    if (testInput != nullptr) {
      delete testInput;
    }
  }
  virtual void SetUp() {
    std::cout << "SetUp" << std::endl;
    wfc_trie = new WFC_Trie();
    testInput = GetParam();
  }
  virtual void TearDown() {
  }

protected:
  TextTestChunk *testInput;
  freq::WFC_Trie *wfc_trie;
};

TEST_P(Test_WFC_Trie, WFC_ValidInut_ValidOutput) {
  if (testInput != nullptr) {
    std::vector<std::pair<std::string, std::size_t>> result;
    std::cerr << "Input string : " << testInput->inputString << "\n";
    wfc_trie->countWordFrequence(testInput->inputString, result);

    EXPECT_EQ(testInput->resultMap, result);
  }
}

INSTANTIATE_TEST_CASE_P(positiveInput_trie, Test_WFC_Trie,
                        ::testing::ValuesIn(positiveInput_trie));
