
#include "LeftistHeap.h"


LeftistHeapNode* LeftistHeap::mergeRoots(LeftistHeapNode *lNode, LeftistHeapNode* rNode) {
    if (lNode == nullptr) {
        return rNode;
    }
    if (rNode == nullptr) {
        return lNode;
    }
    LeftistHeapNode* newRoot;
    LeftistHeapNode* son;
    if (lNode->key < rNode->key) {
        newRoot = lNode;
        son = rNode;
    } else {
        newRoot = rNode;
        son = lNode;
    }
    newRoot->right = mergeRoots(newRoot->right, son);
    if (getNodeDist(newRoot->right) > getNodeDist(newRoot->left)) {
        std::swap(newRoot->left, newRoot->right);
    }
    newRoot->dist = getNodeDist(newRoot->right) + 1;
    return newRoot;
}

void LeftistHeap::Insert(int key) {
    LeftistHeapNode* tmp = new LeftistHeapNode(key);
    head = mergeRoots(head, tmp);
}

int LeftistHeap::GetMin() const {
    if (head == nullptr) {
        return 0;
    }
    return head->key;
}

int LeftistHeap::ExtractMin() {
    if (head == nullptr) {
        return 0;
    }
    int res = head->key;
    // delete
    head = mergeRoots(head->left, head->right);
    return res;
}

void LeftistHeap::merge(LeftistHeap *h) {
    if (this == h) {
        return;
    }
    head = mergeRoots(head, h->head);
}

int LeftistHeap::getNodeDist(LeftistHeapNode *node) {
    if (node == nullptr) {
        return 0;
    } else {
        return node->dist;
    }
}

LeftistHeap::LeftistHeap(int key) {
    Insert(key);
}
