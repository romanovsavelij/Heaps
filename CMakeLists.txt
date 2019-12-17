cmake_minimum_required(VERSION 3.15)
project(Heaps)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Test)

add_executable(Heaps IHeap.h BinomialHeap.cpp BinomialHeap.h BinomialHeapNode.cpp BinomialHeapNode.h StlHeap.cpp StlHeap.h LeftistHeap.cpp LeftistHeap.h SkewHeap.cpp SkewHeap.h Test/test.cpp Operation.cpp Operation.h BinaryHeap.cpp BinaryHeap.h BinaryHeapNode.cpp BinaryHeapNode.h)