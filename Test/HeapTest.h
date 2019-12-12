
#ifndef HEAPS_HEAPTEST_H
#define HEAPS_HEAPTEST_H

#include <vector>
#include <gtest/gtest.h>
#include "../Operation.h"

class HeapTest : public ::testing::Test {
private:
    const int OPERATIONS_COUNT = 1000;

    std::vector <Operation> operations;

    void SetUp() override;
public:
    template <typename HeapType>
    void runTests();
};


#endif //HEAPS_HEAPTEST_H
