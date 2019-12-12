
#ifndef HEAPS_SKEWHEAPNODE_H
#define HEAPS_SKEWHEAPNODE_H


struct SkewHeapNode {
    int key = -1;
    SkewHeapNode* left = nullptr;
    SkewHeapNode* right = nullptr;

    SkewHeapNode() = default;
    explicit SkewHeapNode(int key);
};


#endif //HEAPS_SKEWHEAPNODE_H
