#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#include <stdlib.h>
#include "Point.h"
#include "Cell.h"

class CustomBoard {
    public:
        CustomBoard(int aWidth, int aHeight, int aMines);
        void setWidth(int aWidth);
        void setHeight(int aHeight);
        void setMines(int aMines);
        void putValuesOnBoard(Point firstUncoveredPoint);
        int getWidth() {return width;}
        int getHeight() {return height;}
        int getMines() {return mines;}
        Cell **getBoard() {return board;}
        void uncoverAdjacentNonMinedPoints(Point uncoveredPoint);
        bool isOnBoard(Point point);
        void printBoard();
    private:
        int width, height, mines;
        Cell **board;
        void setBoard();
        void putMinesOnBoard(Point firstUncoveredPoint);
        void putAdjacentMinesCountsOnBoard();
        int countAdjacentMines(Point point);
        char digitToChar(int digit);
};

#endif // CUSTOM_BOARD_H
