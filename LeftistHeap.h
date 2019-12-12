
#ifndef HEAPS_LEFTISTHEAP_H
#define HEAPS_LEFTISTHEAP_H


#include "LeftistHeapNode.h"
#include "IHeap.h"

class LeftistHeap : IHeap {
private:
    LeftistHeapNode* head = nullptr;
    LeftistHeapNode* mergeRoots(LeftistHeapNode* lNode, LeftistHeapNode* rNode);
    int getNodeDist(LeftistHeapNode* node);
public:
    LeftistHeap() = default;
    explicit LeftistHeap(int key);

    void merge(LeftistHeap* h);
    void Insert(int key) override;
    int GetMin() const override;
    int ExtractMin() override;
};


#endif //HEAPS_LEFTISTHEAP_H
