
#ifndef HEAPS_BINOMIALHEAPNODE_H
#define HEAPS_BINOMIALHEAPNODE_H

#include <iostream>

struct BinomialHeapNode {
    int key;
    size_t degree = 0;
    BinomialHeapNode* parent = nullptr;
    BinomialHeapNode* child = nullptr;
    BinomialHeapNode* sibling = nullptr;

    BinomialHeapNode() = default;
    explicit BinomialHeapNode(int key);
};


#endif //HEAPS_BINOMIALHEAPNODE_H
