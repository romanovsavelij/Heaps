
#include "LeftistHeap.h"


LeftistHeapNode* LeftistHeap::_mergeRoots(LeftistHeapNode *lNode, LeftistHeapNode* rNode) {
    if (lNode == nullptr) {
        return rNode;
    }
    if (rNode == nullptr) {
        return lNode;
    }
    LeftistHeapNode* newRoot = rNode;
    LeftistHeapNode* son = lNode;
    if (lNode->key < rNode->key) {
        newRoot = lNode;
        son = rNode;
    }
    newRoot->right = _mergeRoots(newRoot->right, son);
    if (_getNodeDist(newRoot->right) > _getNodeDist(newRoot->left)) {
        std::swap(newRoot->left, newRoot->right);
    }
    newRoot->dist = _getNodeDist(newRoot->right) + 1;
    return newRoot;
}

void LeftistHeap::Insert(int key) {
    LeftistHeapNode* tmp = new LeftistHeapNode(key);
    _head = _mergeRoots(_head, tmp);
}

int LeftistHeap::GetMin() const {
    if (_head == nullptr) {
        return 0;
    }
    return _head->key;
}

void LeftistHeap::ExtractMin() {
    if (_head == nullptr) {
        return;
    }
    delete _head;
    _head = _mergeRoots(_head->left, _head->right);
}

void LeftistHeap::merge(LeftistHeap *h) {
    if (this == h) {
        return;
    }
    _head = _mergeRoots(_head, h->_head);
}

int LeftistHeap::_getNodeDist(LeftistHeapNode *node) {
    if (node == nullptr) {
        return 0;
    } else {
        return node->dist;
    }
}

LeftistHeap::LeftistHeap(int key) {
    Insert(key);
}
