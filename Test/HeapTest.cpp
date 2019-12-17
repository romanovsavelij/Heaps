
#include <fstream>
#include "HeapTest.h"
#include "../StlHeap.h"

void HeapTest::SetUp() {
    const int MAX_KEY_VAL = 1000000;
    srand(4123);
    _operations.resize(_OPERATIONS_COUNT);
    int heapsCounts = 0;
    for (Operation &op : _operations) {
        if (heapsCounts == 0) {
            //std::cout << "add_heap" << std::endl;
            int type = Operation::ADD_HEAP;
            int key = rand() % MAX_KEY_VAL;
            op = Operation(type, key);
            ++heapsCounts;
        } else if (rand() % 2 == 0) {
            //std::cout << "insert" << std::endl;
            int type = Operation::INSERT;
            int index = rand() % heapsCounts;
            int key = rand() % MAX_KEY_VAL;
            op = Operation(type, index, key);
        } else if (rand() % 3 != 0) {
            //std::cout << "get_min" << std::endl;
            int type = Operation::GET_MIN;
            int index = rand() % heapsCounts;
            op = Operation(type, index);
        } else if (rand() % 2 == 0) {
            //std::cout << "extract_min" << std::endl;
            int type = rand() % Operation::EXTRACT_MIN;
            int index = rand() % heapsCounts;
            op = Operation(type, index);
        } else {
            //std::cout << "meld" << std::endl;
            int type = Operation::MELD;
            int index1 = rand() % heapsCounts;
            int index2 = rand() % heapsCounts;
            op = Operation(type, index1, index2);
            --heapsCounts;
        }
    }
    corAns = apply<StlHeap>();
}
