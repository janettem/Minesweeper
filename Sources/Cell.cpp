#include "Cell.h"

using namespace std;

Cell::Cell() {
    setValue('0');
    setState(COVERED);
}

void Cell::setValue(char aValue) {
    if (isValue(aValue)) {
        value = aValue;
    } else {
        value = '0';
    }
}

void Cell::setState(int aState) {
    if (isState(aState)) {
        state = aState;
    } else {
        state = COVERED;
    }
}

bool Cell::isValue(char aValue) {
    if (aValue == MINE ||
    (aValue >= '0' && aValue <= '8')) {
        return true;
    }
    return false;
}

bool Cell::isState(int aState) {
    if (aState == COVERED ||
    aState == UNCOVERED ||
    aState == FLAGGED) {
        return true;
    }
    return false;
}
