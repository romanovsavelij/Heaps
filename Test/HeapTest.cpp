
#include "HeapTest.h"
#include "../StlHeap.h"

void HeapTest::SetUp() {
    const int MAX_KEY_VAL = 100;
    srand(4123);
    operations.resize(OPERATIONS_COUNT);
    int heapsCounts = 0;
    for (Operation &op : operations) {
        int type;
        if (heapsCounts == 0) {
            type = Operation::ADD_HEAP;
            int key = rand() % MAX_KEY_VAL;
            op = Operation(type, key);
            ++heapsCounts;
        }
        type = rand() % Operation::TYPES_COUNT;
        if (type == Operation::INSERT) {
            int index = rand() % heapsCounts;
            int key = rand() % MAX_KEY_VAL;
            op = Operation(type, index, key);
        } else if (type == Operation::GET_MIN) {
            int index = rand() % heapsCounts;
            op = Operation(type, index);
        } else if (type == Operation::EXTRACT_MIN) {
            int index = rand() % heapsCounts;
            op = Operation(type, index);
        } else if (type == Operation::MELD) {
            int index1 = rand() % heapsCounts;
            int index2 = rand() % heapsCounts;
            op = Operation(type, index1, index2);
            --heapsCounts;
        }
    }
}

template <typename HeapType>
void HeapTest::runTests() {
    std::vector <StlHeap> correctHeaps;
    std::vector <HeapType> testingHeaps;

    for (Operation &op: operations) {
        switch (op.type) {

            case Operation::INSERT: {
                correctHeaps[op.index].Insert(op.key);
                testingHeaps[op.index].Insert(op.key);
            }

            case Operation::GET_MIN: {
                ASSERT_EQ(correctHeaps[op.index].GetMin(), testingHeaps[op.index].GetMin());
            }

            case Operation::EXTRACT_MIN: {
                correctHeaps[op.index].ExtractMin();
                testingHeaps[op.index].ExtractMin();
            }

            case Operation::MELD: {
                correctHeaps[op.index].merge(&correctHeaps[op.index1]);
                correctHeaps.erase(correctHeaps.begin() + op.index1);
                testingHeaps[op.index].merge(&testingHeaps[op.index1]);
                testingHeaps.erase(testingHeaps.begin() + op.index1);
            }

            case Operation::ADD_HEAP: {
                correctHeaps.push_back(StlHeap(op.key));
                testingHeaps.push_back(HeapType(op.key));
            }

        }
    }
}