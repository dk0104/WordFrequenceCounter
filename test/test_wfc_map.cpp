#include "TestChunks.h"
#include <cstddef>
#include <gtest/gtest.h>
#include <wfc_map.h>

using ::testing::Bool;
using ::testing::Combine;
using ::testing::TestWithParam;
using ::testing::Values;
using ::testing::ValuesIn;

using namespace std;
using namespace freq;

auto chunk_map1 = new TextTestChunk(
    "wenn fliegen hinter fliegen fliegen, dann fliegen fliegen fliegen nach.",
    {{"fliegen", 6}, {"dann", 1}, {"hinter", 1}, {"nach", 1}, {"wenn", 1}});

auto chunk_map2 = new TextTestChunk(
    "the time has come, the walrus said, to talk of many things",
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

auto chunk_map3 = new TextTestChunk("......------;;;;;:::::", {});
auto chunk_map4 = new TextTestChunk(
    "the&time*has.come,the.walrus:said, to talk)of many things",
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

TestInput positiveInput_map{chunk_map1, chunk_map2,chunk_map3,chunk_map4};
//TestInput invalidInput_map{chunk_map3};

class Test_WFC_Map : public TestWithParam<TextTestChunk *> {
public:
  ~Test_WFC_Map() {
    // if (testInput != nullptr) {
    //   delete testInput;
    // }
  }
  virtual void SetUp() {
    std::cout << "SetUp" << std::endl;
    wfc_map = new WFC_Map();
    testInput = GetParam();
  }
  virtual void TearDown() {}

protected:
  TextTestChunk *testInput;
  freq::WFC_Map *wfc_map;
};

TEST_P(Test_WFC_Map, WFC_ValidInut_ValidOutput) {
  if (testInput != nullptr) {
    std::vector<std::pair<std::string, std::size_t>> result;
    std::cerr << "Input string : " << testInput->inputString << "\n";
    wfc_map->countWordFrequence(testInput->inputString, result);
    EXPECT_EQ(testInput->resultMap, result);
  }
}

TEST_P(Test_WFC_Map, WFC_InValidInut_ErorHandling) {
  if (testInput != nullptr) {
    std::vector<std::pair<std::string, std::size_t>> result;
    std::cerr << "Input string : " << testInput->inputString << "\n";
    wfc_map->countWordFrequence(testInput->inputString, result);
    EXPECT_EQ(testInput->resultMap, result);
  }
}

INSTANTIATE_TEST_CASE_P(positiveInput_map, Test_WFC_Map,
                        ::testing::ValuesIn(positiveInput_map));

