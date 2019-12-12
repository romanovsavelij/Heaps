
#ifndef HEAPS_LEFTISTHEAPNODE_H
#define HEAPS_LEFTISTHEAPNODE_H


struct LeftistHeapNode {
    int key = -1;
    int dist = 0;
    LeftistHeapNode* left = nullptr;
    LeftistHeapNode* right = nullptr;

    LeftistHeapNode() = default;
    explicit LeftistHeapNode(int key);
};


#endif //HEAPS_LEFTISTHEAPNODE_H
