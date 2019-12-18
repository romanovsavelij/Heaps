project(Google_tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run test.cpp ../BinomialHeap.cpp ../BinomialHeapNode.cpp ../LeftistHeap.cpp ../StlHeap.cpp ../SkewHeap.cpp ../Operation.cpp ../Operation.h HeapTest.cpp HeapTest.h ../BinaryHeap.cpp ../BinaryHeap.h ../BinaryHeapNode.cpp ../BinaryHeapNode.h)
target_link_libraries(Google_Tests_run gtest gtest_main)