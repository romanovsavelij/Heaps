#include <iostream>
#include "../BinomialHeap.h"
#include "../StlHeap.h"
#include "../LeftistHeap.h"
#include "../SkewHeap.h"
#include "gtest/gtest.h"
#include "../Operation.h"
#include "HeapTest.h"


TEST_F(HeapTest, BinomialHeapStressTest) {
    clock_t t = clock();
    ASSERT_EQ(corAns, apply<BinomialHeap>());
    const double work_time = (clock() - t) / double(CLOCKS_PER_SEC);
    std::cout << "BinomialHeap work time: " << work_time << std::endl;
}

TEST_F(HeapTest, LeftistHeapStressTestt) {
    clock_t t = clock();
    ASSERT_EQ(corAns, apply<LeftistHeap>());
    const double work_time = (clock() - t) / double(CLOCKS_PER_SEC);
    std::cout << "LeftistHeap work time: " << work_time << std::endl;
}

TEST_F(HeapTest, SkewHeapStressTest) {
    clock_t t = clock();
    ASSERT_EQ(corAns, apply<SkewHeap>());
    const double work_time = (clock() - t) / double(CLOCKS_PER_SEC);
    std::cout << "SkewHeap work time: " << work_time << std::endl;
}


TEST(testBinomialHeap, testOnExamples) {
    BinomialHeap h = BinomialHeap();
    h.insert(3);
    h.insert(1);
    h.insert(2);
    BinomialHeap h1 = BinomialHeap();
    h1.insert(0);
    h1.insert(1);
    h.merge(&h1);
    ASSERT_EQ(h.getMin(), 0);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 1);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 1);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 2);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
