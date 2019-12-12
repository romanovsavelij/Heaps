
#ifndef HEAPS_SKEWHEAP_H
#define HEAPS_SKEWHEAP_H


#include "SkewHeapNode.h"
#include "IHeap.h"

class SkewHeap : IHeap {
private:
    SkewHeapNode* _head = nullptr;
    SkewHeapNode* _mergeRoots(SkewHeapNode* lNode, SkewHeapNode* rNode);
public:
    SkewHeap() = default;
    SkewHeap(int key);

    void merge(SkewHeap* h);
    void Insert(int key) override;
    int GetMin() const override;
    void ExtractMin() override;
};


#endif //HEAPS_SKEWHEAP_H
