#ifndef CELL_H
#define CELL_H

class Cell {
    public:
        const char mine = '*';
        const int covered = 0;
        const int uncovered = 1;
        const int flagged = 2;
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
