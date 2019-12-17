
#include "BinaryHeap.h"

void BinaryHeap::insert(int key) {
    BinaryHeapNode* tmp = new BinaryHeapNode(key);
    _head = mergeRoots(_head, tmp);
}

int BinaryHeap::getMin() const {
    if (_head == nullptr) {
        return 0;
    }
    return _head->key;
}

void BinaryHeap::extractMin() {
    if (_head == nullptr) {
        return;
    }
    delete _head;
    _head = mergeRoots(_head->left, _head->right);
}

void BinaryHeap::merge(BinaryHeap *h) {
    if (this == h) {
        return;
    }
    _head = mergeRoots(_head, h->_head);
}

BinaryHeap::BinaryHeap(int key) {
    insert(key);
}

BinaryHeapNode *BinaryHeap::mergeRoots(BinaryHeapNode *lNode, BinaryHeapNode *rNode) {
    if (lNode == nullptr) {
        return rNode;
    }
    if (rNode == nullptr) {
        return lNode;
    }
    BinaryHeapNode* newRoot = rNode;
    BinaryHeapNode* son = lNode;
    if (lNode->key < rNode->key) {
        newRoot = lNode;
        son = rNode;
    }
    newRoot->right = mergeRoots(newRoot->right, son);
    fixBalance(newRoot);
    return newRoot;
}
