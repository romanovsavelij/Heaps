#include <iostream>
#include "../BinomialHeap.h"
#include "../StlHeap.h"
#include "../LeftistHeap.h"
#include "../SkewHeap.h"
#include "gtest/gtest.h"
#include "../Operation.h"
#include "HeapTest.h"


TEST_F(HeapTest, BinomialHeapStressTest) {
    runTests<BinomialHeap>();
}

TEST_F(HeapTest, LeftistHeapStressTestt) {
    runTests<LeftistHeap>();
}

TEST_F(HeapTest, SkewHeapStressTest) {
    runTests<SkewHeap>();
}

TEST_F(HeapTest, StlHeapStressTest) {
    runTests<StlHeap>();
}

TEST(testBinomialHeap, testOnExamples) {
    BinomialHeap h = BinomialHeap();
    h.Insert(3);
    h.Insert(1);
    h.Insert(2);
    BinomialHeap h1 = BinomialHeap();
    h1.Insert(0);
    h1.Insert(1);
    h.merge(&h1);
    ASSERT_EQ(h.GetMin(), 0);
    h.ExtractMin();
    ASSERT_EQ(h.GetMin(), 1);
    h.ExtractMin();
    ASSERT_EQ(h.GetMin(), 1);
    h.ExtractMin();
    ASSERT_EQ(h.GetMin(), 2);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
