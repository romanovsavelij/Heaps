#include <iostream>
#include "../BinomialHeap.h"
#include "../StlHeap.h"
#include "../LeftistHeap.h"
#include "../SkewHeap.h"
#include "gtest/gtest.h"
#include "../Operation.h"
#include "HeapTest.h"


TEST_F(HeapTest, BinomialHeapStressTest) {
    testHeap<BinomialHeap>();
}

TEST_F(HeapTest, LeftistHeapStressTestt) {
    testHeap<LeftistHeap>();
}

TEST_F(HeapTest, SkewHeapStressTest) {
    testHeap<SkewHeap>();
}

template <typename HeapType>
void testDeleteAllElements() {
    HeapType h = HeapType();
    h.insert(-1);
    h.insert(0);
    h.insert(1);
    ASSERT_EQ(h.getMin(), -1);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 0);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 1);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 0);
}

TEST(SmallTests, TestBinomialHeapDeletingAllElements) {
    testDeleteAllElements<BinomialHeap>();
}

TEST(SmallTests, TestLeftistHeapDeletingAllElements) {
    testDeleteAllElements<LeftistHeap>();
}

TEST(SmallTests, TestSkewHeapDeletingAllElements) {
    testDeleteAllElements<SkewHeap>();
}

template <typename HeapType>
void testAddSameElements() {
    HeapType h = HeapType();
    h.insert(0);
    h.insert(0);
    h.insert(1);
    h.insert(1);
    h.insert(1);
    ASSERT_EQ(h.getMin(), 0);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 0);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 1);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 1);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 1);
    h.extractMin();
    ASSERT_EQ(h.getMin(), 0);
}

TEST(SmallTests, TestBinomialHeapAddingSameElements) {
    testAddSameElements<BinomialHeap>();
}

TEST(SmallTests, TestLeftistHeapAddingSameElements) {
    testAddSameElements<LeftistHeap>();
}

TEST(SmallTests, TestSkewHeapAddingSameElements) {
    testAddSameElements<SkewHeap>();
}

template <typename HeapType>
void testMeld() {
    BinomialHeap h = BinomialHeap();
    BinomialHeap h2 = BinomialHeap();
    h.merge(&h2);
    h.insert(3);
    ASSERT_EQ(h.getMin(), 3);
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

TEST(SmallTests, TestBinomialHeapMeld) {
    testMeld<BinomialHeap>();
}

TEST(SmallTests, TestLiftistHeapMeld) {
    testMeld<LeftistHeap>();
}

TEST(SmallTests, TestSkewHeapMeld) {
    testMeld<SkewHeap>();
}

template <typename HeapType>
void testMax() {
    clock_t t = clock();
    const int ELEMENTS_CNT = 1000000;
    std::vector <HeapType> heaps(ELEMENTS_CNT);
    for (size_t i = 0; i < ELEMENTS_CNT; ++i) {
        heaps[i] = HeapType(ELEMENTS_CNT - i);
    }
    for (size_t i = 1; i < ELEMENTS_CNT; ++i) {
        heaps[0].merge(&heaps[i]);
        ASSERT_EQ(heaps[0].getMin(), ELEMENTS_CNT - i);
    }
    const double work_time = (clock() - t) / double(CLOCKS_PER_SEC);
    ASSERT_LE(work_time, 0.5);
}

TEST(MaxTests, TestMaxBinomialHeap) {
    testMax<BinomialHeap>();
}

TEST(MaxTests, TestMaxLeftistHeap) {
    testMax<LeftistHeap>();
}

TEST(MaxTests, TestMaxSkewHeap) {
    testMax<SkewHeap>();
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
