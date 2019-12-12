
#ifndef HEAPS_BINOMIALHEAP_H
#define HEAPS_BINOMIALHEAP_H


#include "IHeap.h"
#include "BinomialHeapNode.h"

class BinomialHeap : public IHeap {
private:
    BinomialHeapNode* head;
public:
    BinomialHeap() = default;
    BinomialHeap(BinomialHeapNode *node);
    BinomialHeap(int key);

    void merge(BinomialHeap* h);
    int GetMin() const override;
    void Insert(int key) override;
    int ExtractMin() override;
};


#endif //HEAPS_BINOMIALHEAP_H
