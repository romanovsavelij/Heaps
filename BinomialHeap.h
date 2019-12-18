
#ifndef HEAPS_BINOMIALHEAP_H
#define HEAPS_BINOMIALHEAP_H


#include "IHeap.h"
#include "BinomialHeapNode.h"

class BinomialHeap : public IHeap {
private:
    BinomialHeapNode* _head;
    void _mergeInLine(BinomialHeap* h);
    void _mergeSameDegreeTrees();
    BinomialHeapNode* _removeMinTreeReturnChild();
    void _getNeighborsList(BinomialHeapNode* node, std::vector <BinomialHeapNode*>& list) const;
    BinomialHeap* _createHeapByNodeList(std::vector <BinomialHeapNode*>& list);
    void _addSequentially(BinomialHeapNode* mainHeapNode, BinomialHeapNode* addingHeapNode);
    void _mergeSameDegreeNeighbours(BinomialHeapNode* node);
public:
    BinomialHeap() = default;
    explicit BinomialHeap(BinomialHeapNode *node);
    explicit BinomialHeap(int key);

    void merge(BinomialHeap* h);
    int getMin() const override;
    void insert(int key) override;
    void extractMin() override;
};


#endif //HEAPS_BINOMIALHEAP_H
