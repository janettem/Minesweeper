#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include "Point.h"
#include "Cell.h"

class Board {
    public:
        Board(int aWidth, int aHeight, int aMines);
        void setWidth(int aWidth);
        void setHeight(int aHeight);
        void setMines(int aMines);
        int getWidth() {return width;}
        int getHeight() {return height;}
        int getMines() {return mines;}
        Cell **getBoard() {return board;}
        void putValuesOnBoard(Point firstUncoveredPoint);
        bool hasCoveredNonMinePoints();
        void playTurn(Point point, int state);
        void printBoard();
    private:
        int width, height, mines;
        Cell **board;
        void setBoard();
        void putMinesOnBoard(Point firstUncoveredPoint);
        void putAdjacentMinesCountsOnBoard();
        int countAdjacentMines(Point point);
        void uncoverAdjacentNonMinePoints(Point uncoveredPoint);
        bool isOnBoard(Point point);
        char digitToChar(int digit);
};

#endif // BOARD_H
