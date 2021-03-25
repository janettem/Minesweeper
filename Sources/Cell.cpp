#include "Cell.h"

using namespace std;

Cell::Cell() {
    setValue('0');
    setState(covered);
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
        state = covered;
    }
}

bool Cell::isState(int aState) {
    if (aState == covered ||
    aState == uncovered ||
    aState == flagged) {
        return true;
    }
    return false;
}

bool Cell::isValue(char aValue) {
    if (aValue == mine ||
    (aValue >= '0' && aValue <= '8')) {
        return true;
    }
    return false;
}
