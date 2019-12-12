
#ifndef HEAPS_STLHEAP_H
#define HEAPS_STLHEAP_H


#include <vector>
#include "IHeap.h"

class StlHeap : public IHeap {
private:
    std::vector<int> data;
public:
    StlHeap() = default;
    StlHeap(int key);

    void merge(StlHeap* ms);
    void Insert(int key) override;
    int GetMin() const override;
    int ExtractMin() override;
};


#endif //HEAPS_STLHEAP_H
