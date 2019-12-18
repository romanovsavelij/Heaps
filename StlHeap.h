
#ifndef HEAPS_STLHEAP_H
#define HEAPS_STLHEAP_H


#include <vector>
#include "IHeap.h"

class StlHeap : public IHeap {
private:
    std::vector<int> _data;
public:
    StlHeap() = default;
    explicit StlHeap(int key);

    void merge(StlHeap* ms);
    void insert(int key) override;
    int getMin() const override;
    void extractMin() override;
};


#endif //HEAPS_STLHEAP_H
