cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
include_directories(/usr/include/gtest)
link_directories(/usr/lib/gtest)

# Set Compiler Flags 
set (CMAKE_CXX_FLAGS "-std=c++11 -lm -g")
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(testWavefunction testWavefunction.cpp ../wavefunction.cpp)
target_link_libraries(testWavefunction gtest gtest_main pthread)


