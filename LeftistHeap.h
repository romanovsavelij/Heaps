
#ifndef HEAPS_LEFTISTHEAP_H
#define HEAPS_LEFTISTHEAP_H


#include "LeftistHeapNode.h"
#include "IHeap.h"

class LeftistHeap : IHeap {
private:
    LeftistHeapNode* _head = nullptr;
    LeftistHeapNode* _mergeRoots(LeftistHeapNode* lNode, LeftistHeapNode* rNode);
    int _getNodeDist(LeftistHeapNode* node);
public:
    LeftistHeap() = default;
    explicit LeftistHeap(int key);

    void merge(LeftistHeap* h);
    void Insert(int key) override;
    int GetMin() const override;
    void ExtractMin() override;
};


#endif //HEAPS_LEFTISTHEAP_H
