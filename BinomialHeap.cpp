
#include <vector>
#include "BinomialHeap.h"


void BinomialHeap::_addSequentially(BinomialHeapNode *mainHeapNode, BinomialHeapNode *addingHeapNode) {
    if (addingHeapNode == nullptr) {
        return;
    }
    while (addingHeapNode != nullptr) {
        mainHeapNode->sibling = addingHeapNode;
        mainHeapNode = addingHeapNode;
        addingHeapNode = addingHeapNode->sibling;
    }
}

void BinomialHeap::_mergeInLine(BinomialHeap* h) {
    BinomialHeap* resHeap = new BinomialHeap();
    BinomialHeapNode* curResHeapNode = resHeap->_head;
    BinomialHeapNode* curH1Tree = this->_head;
    BinomialHeapNode* curH2Tree = h->_head;
    while (curH1Tree != nullptr && curH2Tree != nullptr) {
        BinomialHeapNode*& next = curH2Tree;
        if (curH1Tree->degree < curH2Tree->degree) {
            next = curH1Tree;
        }
        if (curResHeapNode != nullptr) {
            curResHeapNode->sibling = next;
        }
        curResHeapNode = next;
        next = next->sibling;
        if (resHeap->_head == nullptr) {
            resHeap->_head = curResHeapNode;
        }
    }
    _addSequentially(curResHeapNode, curH1Tree);
    _addSequentially(curResHeapNode, curH2Tree);
    _head = resHeap->_head;
};

void BinomialHeap::merge(BinomialHeap* h) {
    if (this == h) {
        return;
    }
    if (h == nullptr || h->_head == nullptr) {
        return;
    }
    if (_head == nullptr) {
        _head = h->_head;
        return;
    }
    _mergeInLine(h);
    _mergeSameDegreeTrees();
}

int BinomialHeap::GetMin() const {
    if (_head == nullptr) {
        return 0;
    }
    BinomialHeapNode* root = _head;
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

BinomialHeapNode* BinomialHeap::_removeMinTreeReturnChild() {
    BinomialHeapNode* curTree = _head;
    BinomialHeapNode* curMin = _head;
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
        _head = curMin->sibling;
    } else {
        prevToMin->sibling = curMin->sibling;
    }
    BinomialHeapNode* child = curMin->child;
    delete curMin;
    return child;
}

void BinomialHeap::_getNeighborsList(BinomialHeapNode *node, std::vector<BinomialHeapNode *>& list) const {
    while (node != nullptr) {
        node->parent = nullptr;
        list.push_back(node);
        node = node->sibling;
    }
    reverse(list.begin(), list.end());
}

BinomialHeap *BinomialHeap::_createHeapByNodeList(std::vector<BinomialHeapNode *> &list) {
    BinomialHeap* h;
    if (list.empty()) {
        h = nullptr;
    } else {
        h = new BinomialHeap(list[0]);
        for (int i = 0; i + 1 < list.size(); ++i) {
            list[i]->sibling = list[i + 1];
        }
        list.back()->sibling = nullptr;
    }
    return h;
}

void BinomialHeap::ExtractMin() {
    if (_head == nullptr) {
        return;
    }
    BinomialHeapNode* curChild = _removeMinTreeReturnChild();

    std::vector <BinomialHeapNode*> childrenList;
    _getNeighborsList(curChild, childrenList);

    for (int i = 0; i + 1 < childrenList.size(); ++i) {
        childrenList[i]->parent = nullptr;
    }
    if (!childrenList.empty()) {
        childrenList.back()->parent = nullptr;
    }

    BinomialHeap* h = _createHeapByNodeList(childrenList);

    merge(h);
}

BinomialHeap::BinomialHeap(BinomialHeapNode *node) {
    _head = node;
}

BinomialHeap::BinomialHeap(int key) : BinomialHeap(new BinomialHeapNode(key)) {}

void BinomialHeap::_mergeSameDegreeNeighbours(BinomialHeapNode *node) {
    if (node->key > node->sibling->key) {
        node->parent = node->sibling;
        auto prevChild = node->sibling->child;
        node->sibling->child = node;
        node->sibling = prevChild;
    } else {
        auto righterTree = node->sibling->sibling;
        node->sibling->parent = node;
        node->sibling->sibling = node->child;
        node->child = node->sibling;
        node->sibling = righterTree;
    }
}

void BinomialHeap::_mergeSameDegreeTrees() {
    BinomialHeapNode *curHeapNode = _head;
    BinomialHeapNode *prev = new BinomialHeapNode();
    prev->sibling = _head;
    while (curHeapNode->sibling != nullptr) {
        if (curHeapNode->degree == curHeapNode->sibling->degree) {
            BinomialHeapNode* root = curHeapNode;
            if (curHeapNode->key > curHeapNode->sibling->key) {
                root = curHeapNode->sibling;
            }
            if (prev->sibling == _head) {
                _head = root;
            }
            prev->sibling = root;
            _mergeSameDegreeNeighbours(curHeapNode);
        } else {
            prev = prev->sibling;
        }
        curHeapNode = prev->sibling;
    }
}
