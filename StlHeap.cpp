
#include "StlHeap.h"


int StlHeap::GetMin() const {
    if (data.empty()) {
        return 0;
    }
    return *std::min_element(data.begin(), data.end());
}

void StlHeap::Insert(int key) {
    data.push_back(key);
}

int StlHeap::ExtractMin() {
    if (data.empty()) {
        return 0;
    }
    auto it = std::min_element(data.begin(), data.end());
    int res = *it;
    data.erase(it);
    return res;
}

void StlHeap::merge(StlHeap *ms) {
    if (this == ms) {
        return;
    }
    data.insert(data.end(), ms->data.begin(), ms->data.end());
}

StlHeap::StlHeap(int key) {
    data.push_back(key);
}



