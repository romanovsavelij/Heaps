
#include "StlHeap.h"


int StlHeap::GetMin() const {
    if (_data.empty()) {
        return 0;
    }
    return *std::min_element(_data.begin(), _data.end());
}

void StlHeap::Insert(int key) {
    _data.push_back(key);
}

void StlHeap::ExtractMin() {
    if (_data.empty()) {
        return;
    }
    auto it = std::min_element(_data.begin(), _data.end());
    _data.erase(it);
}

void StlHeap::merge(StlHeap *ms) {
    if (this == ms) {
        return;
    }
    _data.insert(_data.end(), ms->_data.begin(), ms->_data.end());
}

StlHeap::StlHeap(int key) {
    _data.push_back(key);
}



