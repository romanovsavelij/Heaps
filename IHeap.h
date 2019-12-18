
#ifndef HEAPS_IHEAP_H
#define HEAPS_IHEAP_H

#include <iostream>

class IHeap {
public:
    // Mergeable heap
    virtual void insert(int key) = 0;
    virtual int getMin() const = 0;
    virtual void extractMin() = 0;
};

#endif //HEAPS_IHEAP_H
