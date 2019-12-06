cmake_minimum_required(VERSION 3.15)
project(Heaps)

set(CMAKE_CXX_STANDARD 17)

add_executable(Heaps main.cpp IHeap.h BinomialHeap.cpp BinomialHeap.h)