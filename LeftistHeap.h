
#ifndef HEAPS_LEFTISTHEAP_H
#define HEAPS_LEFTISTHEAP_H


#include "BinaryHeapNode.h"
#include "BinaryHeap.h"

class LeftistHeap : public BinaryHeap {
private:
    int _getNodeDist(BinaryHeapNode* node);
public:
    LeftistHeap() = default;
    explicit LeftistHeap(int key);

    void fixBalance(BinaryHeapNode* node) override;
};


#endif //HEAPS_LEFTISTHEAP_H
