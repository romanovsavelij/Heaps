
#ifndef HEAPS_SKEWHEAP_H
#define HEAPS_SKEWHEAP_H


#include "IHeap.h"
#include "BinaryHeapNode.h"
#include "BinaryHeap.h"

class SkewHeap : public BinaryHeap {
public:
    SkewHeap() = default;
    explicit SkewHeap(int key);

    void fixBalance(BinaryHeapNode* node) override;
};


#endif //HEAPS_SKEWHEAP_H
