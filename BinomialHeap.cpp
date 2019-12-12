
#include <vector>
#include "BinomialHeap.h"


void BinomialHeap::merge(BinomialHeap* h) {
    if (this == h) {
        return;
    }
    if (h == nullptr || h->head == nullptr) {
        return;
    }
    if (head == nullptr) {
        head = h->head;
        return;
    }
    BinomialHeap* resHeap = new BinomialHeap();
    BinomialHeapNode* curResHeapNode = resHeap->head;
    BinomialHeapNode* curH1Tree = this->head;
    BinomialHeapNode* curH2Tree = h->head;
    while (curH1Tree != nullptr && curH2Tree != nullptr) {
        if (curH1Tree->degree < curH2Tree->degree) {
            if (curResHeapNode != nullptr) {
                curResHeapNode->sibling = curH1Tree;
            }
            curResHeapNode = curH1Tree;
            if (resHeap->head == nullptr) {
                resHeap->head = curResHeapNode;
            }
            curH1Tree = curH1Tree->sibling;
        } else {
            if (curResHeapNode != nullptr) {
                curResHeapNode->sibling = curH2Tree;
            }
            curResHeapNode = curH2Tree;
            if (resHeap->head == nullptr) {
                resHeap->head = curResHeapNode;
            }
            curH2Tree = curH2Tree->sibling;
        }
    }
    if (curH1Tree == nullptr) {
        while (curH2Tree != nullptr) {
            curResHeapNode->sibling = curH2Tree;
            curResHeapNode = curH2Tree;
            curH2Tree = curH2Tree->sibling;
        }
    } else {
        while (curH1Tree != nullptr) {
            curResHeapNode->sibling = curH1Tree;
            curResHeapNode = curH1Tree;
            curH1Tree = curH1Tree->sibling;
        }
    }
    curResHeapNode = resHeap->head;
    BinomialHeapNode* prev = new BinomialHeapNode();
    prev->sibling = resHeap->head;
    while (curResHeapNode->sibling != nullptr) {
        if (curResHeapNode->degree == curResHeapNode->sibling->degree) {
            if (curResHeapNode->key > curResHeapNode->sibling->key) {
                if (prev->sibling == resHeap->head) {
                    resHeap->head = curResHeapNode->sibling;
                }
                prev->sibling = curResHeapNode->sibling;
                curResHeapNode->parent = curResHeapNode->sibling;
                auto prevChild = curResHeapNode->sibling->child;
                curResHeapNode->sibling->child = curResHeapNode;
                curResHeapNode->sibling = prevChild;
            } else {
                if (prev->sibling == resHeap->head) {
                    resHeap->head = curResHeapNode;
                }
                prev->sibling = curResHeapNode;
                auto righterTree = curResHeapNode->sibling->sibling;
                curResHeapNode->sibling->parent = curResHeapNode;
                curResHeapNode->sibling->sibling = curResHeapNode->child;
                curResHeapNode->child = curResHeapNode->sibling;
                curResHeapNode->sibling = righterTree;
            }
        } else {
            prev = prev->sibling;
        }
        curResHeapNode = prev->sibling;
    }
    this -> head = resHeap->head;
}

int BinomialHeap::GetMin() const {
    if (head == nullptr) {
        return 0;
    }
    BinomialHeapNode* root = head;
    int res = root -> key;
    root = root -> sibling;
    while (root != nullptr) {
        res = std::min(res, root -> key);
        root = root -> sibling;
    }
    return res;
}

void BinomialHeap::Insert(int key) {
    auto h = new BinomialHeap(new BinomialHeapNode(key));
    merge(h);
}

int BinomialHeap::ExtractMin() {
    if (head == nullptr) {
        return 0;
    }
    // finding min tree
    BinomialHeapNode* curTree = head;
    BinomialHeapNode* curMin = head;
    BinomialHeapNode* prevToMin = nullptr;
    while (curTree->sibling != nullptr) {
        BinomialHeapNode* tmp = curTree->sibling;
        if (tmp->key < curMin->key) {
            curMin = tmp;
            prevToMin = curTree;
        }
        curTree = tmp;
    }
    if (prevToMin == nullptr) {
        head = curMin->sibling;
    } else {
        prevToMin->sibling = curMin->sibling;
    }

    std::vector <BinomialHeapNode*> childrenList;
    BinomialHeapNode* curChild = curMin->child;
    while (curChild != nullptr) {
        curChild->parent = nullptr;
        childrenList.push_back(curChild);
        curChild = curChild->sibling;
    }
    reverse(childrenList.begin(), childrenList.end());

    delete curMin;

    BinomialHeap* h;
    if (childrenList.empty()) {
        h = nullptr;
    } else {
        h = new BinomialHeap(childrenList[0]);
        for (int i = 0; i + 1 < childrenList.size(); ++i) {
            childrenList[i]->sibling = childrenList[i + 1];
        }
        childrenList.back()->sibling = nullptr;
    }

    merge(h);

    return 0;
}

BinomialHeap::BinomialHeap(BinomialHeapNode *node) {
    head = node;
}

BinomialHeap::BinomialHeap(int key) : BinomialHeap(new BinomialHeapNode(key)) {};
