
#include "SkewHeap.h"


SkewHeapNode* SkewHeap::_mergeRoots(SkewHeapNode *lNode, SkewHeapNode* rNode) {
    if (lNode == nullptr) {
        return rNode;
    }
    if (rNode == nullptr) {
        return lNode;
    }
    SkewHeapNode* newRoot;
    SkewHeapNode* son;
    if (lNode->key < rNode->key) {
        newRoot = lNode;
        son = rNode;
    } else {
        newRoot = rNode;
        son = lNode;
    }
    newRoot->right = _mergeRoots(newRoot->right, son);
    std::swap(newRoot->left, newRoot->right);
    return newRoot;
}

void SkewHeap::Insert(int key) {
    SkewHeapNode* tmp = new SkewHeapNode(key);
    _head = _mergeRoots(_head, tmp);
}

int SkewHeap::GetMin() const {
    if (_head == nullptr) {
        return 0;
    }
    return _head->key;
}

void SkewHeap::ExtractMin() {
    if (_head == nullptr) {
        return;
    }
    delete _head;
    _head = _mergeRoots(_head->left, _head->right);
}

void SkewHeap::merge(SkewHeap *h) {
    if (this == h) {
        return;
    }
    _head = _mergeRoots(_head, h->_head);
}

SkewHeap::SkewHeap(int key) {
    Insert(key);
}


