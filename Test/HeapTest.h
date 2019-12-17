
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
    std::vector <int> corAns;
    template <typename HeapType>
    std::vector <int> apply();
};

template <typename HeapType>
std::vector <int> HeapTest::apply() {
    std::vector <HeapType> heaps;
    std::vector <int> ans;
    for (Operation &op: _operations) {
        switch (op.type) {

            case Operation::INSERT: {
                heaps[op.index].insert(op.key);
                break;
            }

            case Operation::GET_MIN: {
                ans.push_back(heaps[op.index].getMin());
                break;
            }

            case Operation::EXTRACT_MIN: {
                heaps[op.index].extractMin();
                break;
            }

            case Operation::MELD: {
                heaps[op.index].merge(&heaps[op.index1]);
                heaps.erase(heaps.begin() + op.index1);
                break;
            }

            case Operation::ADD_HEAP: {
                heaps.push_back(HeapType(op.key));
                break;
            }

        }
    }
    return ans;
}

#endif //HEAPS_HEAPTEST_H
