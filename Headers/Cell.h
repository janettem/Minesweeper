#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell {
    public:
        Cell();
        void setValue(char aValue);
        void setState(std::string aState);
        char getValue() {return value;}
        std::string getState() {return state;}
    private:
        char value;
        std::string state;
        bool isValue(char aValue);
        bool isState(std::string aState);
};

#endif // CELL_H
