
#include "LeftistHeap.h"

int LeftistHeap::_getNodeDist(BinaryHeapNode *node) {
    if (node == nullptr) {
        return 0;
    } else {
        return node->dist;
    }
}

LeftistHeap::LeftistHeap(int key) {
    insert(key);
}

void LeftistHeap::fixBalance(BinaryHeapNode* node) {
    if (_getNodeDist(node->right) > _getNodeDist(node->left)) {
        std::swap(node->left, node->right);
    }
    node->dist = _getNodeDist(node->right) + 1;
}
