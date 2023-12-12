## Installation and build instruction
### Setup
'conan install . --output-folder=build --build=missing'

***

### Config and Build 

'cmake -S .build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build'

### Targets
There is multiple targets configured for each application

freq_bin which build result is located in  /build/src/freq
freq_Tests -> /build/test/freq_Tests
freq_Benchmark -> /build/benchmark/freq_Benchmark

### Execution output 
'
~/s/f/b/src ❯❯./freq in.txt out.txt                                                                                                                                                                                                     
~/s/f/b/src ❯❯❯ cat out.txt
2 the
1 come
1 has
1 many
1 of
1 said
1 talk
1 things
1 time
1 to 1 walrus '
### Resume
'
2023-05-17T13:22:06+02:00 Running ./freq_Benchmark
RUN ON (16 X 1700 MHZ CPU S)
CPU CACHES:
  L1 DATA 32 KIB (X8)
  L1 INSTRUCTION 32 KIB (X8)
  L2 UNIFIED 512 KIB (X8)
  L3 UNIFIED 4096 KIB (X2)
LOAD AVERAGE: 0.36, 0.21, 0.27
***WARNING*** CPU SCALING IS ENABLED, THE BENCHMARK REAL TIME MEASUREMENTS MAY BE NOISY AND WILL INCUR EXTRA OVERHEAD.
------------------------------------------------------
Benchmark            Time             CPU   Iterations
------------------------------------------------------
BM_WFC_MAP     1102486 ns      1101650 ns         1000
BM_WFC_TRIE       1084 ns         1083 ns       639690
'

The current solution includes two approaches to word occurrence frequency counters. The first is the naiv one, which is based on an undordered_map.  The second solution is based on prefix trie and is preferred due to its shorter runtime.The runtime evaluation was carried out using the Google Benchmark library, and the results can be seen above.
