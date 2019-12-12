
#ifndef HEAPS_SKEWHEAP_H
#define HEAPS_SKEWHEAP_H


#include "SkewHeapNode.h"
#include "IHeap.h"

class SkewHeap : IHeap {
private:
    SkewHeapNode* head = nullptr;
    SkewHeapNode* mergeRoots(SkewHeapNode* lNode, SkewHeapNode* rNode);
public:
    SkewHeap() = default;
    SkewHeap(int key);

    void merge(SkewHeap* h);
    void Insert(int key) override;
    int GetMin() const override;
    int ExtractMin() override;
};


#endif //HEAPS_SKEWHEAP_H
