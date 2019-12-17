
#ifndef HEAPS_BINARYHEAPNODE_H
#define HEAPS_BINARYHEAPNODE_H


struct BinaryHeapNode {
    int key = -1;
    int dist = 0;
    BinaryHeapNode* left = nullptr;
    BinaryHeapNode* right = nullptr;


    BinaryHeapNode() = default;
    explicit BinaryHeapNode(int key);
};


#endif //HEAPS_BINARYHEAPNODE_H
