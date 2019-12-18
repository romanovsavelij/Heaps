
#ifndef HEAPS_OPERATION_H
#define HEAPS_OPERATION_H


#include <assert.h>

struct Operation {
    static const int TYPES_COUNT = 5;
    static const int INSERT = 0;
    static const int GET_MIN = 1;
    static const int EXTRACT_MIN = 2;
    static const int MELD = 3;
    static const int ADD_HEAP = 4;

    int type;
    int index;
    int index1;
    int key;

    Operation() = default;
    Operation(int type, int par1, int par2 = -1);
};


#endif //HEAPS_OPERATION_H
