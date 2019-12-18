
#include "SkewHeap.h"


void SkewHeap::fixBalance(BinaryHeapNode* node) {
    std::swap(node->left, node->right);
}

SkewHeap::SkewHeap(int key) {
    insert(key);
}


