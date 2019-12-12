
#ifndef HEAPS_IHEAP_H
#define HEAPS_IHEAP_H

#include <iostream>

class IHeap {
public:
    virtual void Insert(int key) = 0;
    virtual int GetMin() const = 0;
    virtual void ExtractMin() = 0;
};

#endif //HEAPS_IHEAP_H
