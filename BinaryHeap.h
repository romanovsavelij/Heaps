
#ifndef HEAPS_BINARYHEAP_H
#define HEAPS_BINARYHEAP_H


#include "BinaryHeapNode.h"
#include "IHeap.h"

class BinaryHeap : public IHeap {
    private:
        BinaryHeapNode* _head = nullptr;
    public:
        BinaryHeap() = default;
        explicit BinaryHeap(int key);

        virtual void fixBalance(BinaryHeapNode* node) = 0;
        BinaryHeapNode* mergeRoots(BinaryHeapNode* lNode, BinaryHeapNode* rNode);
        void merge(BinaryHeap* h);
        void insert(int key) override;
        int getMin() const override;
        void extractMin() override;
};


#endif //HEAPS_BINARYHEAP_H
