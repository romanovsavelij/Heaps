#include "Operation.h"


Operation::Operation(int type, int par1, int par2) {
    this -> type = type;
    if (type == INSERT) {
        index = par1;
        key = par2;
    } else if (type == GET_MIN) {
        index = par1;
    } else if (type == EXTRACT_MIN) {
        index = par1;
    } else if (type == MELD) {
        index = par1;
        index1 = par2;
    } else if (type == ADD_HEAP) {
        key = par1;
    } else {
        assert("unknown operation type");
    }
}