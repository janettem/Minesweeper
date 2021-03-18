#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <iostream>

class Board {
    public:
        Board(int aWidth, int aHeight, int aMines);
        void setWidth(int aWidth);
        void setHeight(int aHeight);
        void setMines(int aMines);
        void setBoard();
        int getWidth() {return width;}
        int getHeight() {return height;}
        int getMines() {return mines;}
        Cell **getBoard() {return board;}
        void printBoard();
    private:
        int width, height, mines;
        Cell **board;
};

#endif // BOARD_H
