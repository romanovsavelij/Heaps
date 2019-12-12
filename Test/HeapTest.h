
#ifndef HEAPS_HEAPTEST_H
#define HEAPS_HEAPTEST_H

#include <vector>
#include <gtest/gtest.h>
#include "../Operation.h"
#include "../StlHeap.h"

class HeapTest : public ::testing::Test {
private:
    const int _OPERATIONS_COUNT = 1000000;

    std::vector <Operation> _operations;
protected:
    void SetUp() override;
public:
    template <typename HeapType>
    void runTests();
};

template <typename HeapType>
void HeapTest::runTests() {
    std::vector <StlHeap> correctHeaps;
    std::vector <HeapType> testingHeaps;

    for (Operation &op: _operations) {
        switch (op.type) {

            case Operation::INSERT: {
                correctHeaps[op.index].Insert(op.key);
                testingHeaps[op.index].Insert(op.key);
                break;
            }

            case Operation::GET_MIN: {
                ASSERT_EQ(correctHeaps[op.index].GetMin(), testingHeaps[op.index].GetMin());
                break;
            }

            case Operation::EXTRACT_MIN: {
                correctHeaps[op.index].ExtractMin();
                testingHeaps[op.index].ExtractMin();
                break;
            }

            case Operation::MELD: {
                correctHeaps[op.index].merge(&correctHeaps[op.index1]);
                correctHeaps.erase(correctHeaps.begin() + op.index1);
                testingHeaps[op.index].merge(&testingHeaps[op.index1]);
                testingHeaps.erase(testingHeaps.begin() + op.index1);
                break;
            }

            case Operation::ADD_HEAP: {
                correctHeaps.push_back(StlHeap(op.key));
                testingHeaps.push_back(HeapType(op.key));
                break;
            }

        }
    }
}

#endif //HEAPS_HEAPTEST_H
