#ifndef CELL_H
#define CELL_H

#include <iostream>

#define MINE '*'
#define COVERED 0
#define UNCOVERED 1
#define FLAGGED 2

class Cell {
    public:
        Cell();
        void setValue(char aValue);
        void setState(int aState);
        char getValue() {return value;}
        int getState() {return state;}
    private:
        char value;
        int state;
        bool isValue(char aValue);
        bool isState(int aState);
};

#endif // CELL_H
