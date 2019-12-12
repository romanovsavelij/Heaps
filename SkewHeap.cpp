
#include "SkewHeap.h"


SkewHeapNode* SkewHeap::mergeRoots(SkewHeapNode *lNode, SkewHeapNode* rNode) {
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
    newRoot->right = mergeRoots(newRoot->right, son);
    std::swap(newRoot->left, newRoot->right);
    return newRoot;
}

void SkewHeap::Insert(int key) {
    SkewHeapNode* tmp = new SkewHeapNode(key);
    head = mergeRoots(head, tmp);
}

int SkewHeap::GetMin() const {
    if (head == nullptr) {
        return 0;
    }
    return head->key;
}

int SkewHeap::ExtractMin() {
    if (head == nullptr) {
        return 0;
    }
    int res = head->key;
    // delete
    head = mergeRoots(head->left, head->right);
    return res;
}

void SkewHeap::merge(SkewHeap *h) {
    if (this == h) {
        return;
    }
    head = mergeRoots(head, h->head);
}

SkewHeap::SkewHeap(int key) {
    Insert(key);
}


