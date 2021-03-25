#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Point.h"
#include "Cell.h"
#include "Console.h"

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
        bool isOnBoard(Point point);
        void printBoard(Point lastPoint);
        void printBoardMines(Point lastPoint);
    private:
        int width, height, mines;
        Cell **board;
        Cell cell;
        Console console;
        void setBoard();
        void putMinesOnBoard(Point firstUncoveredPoint);
        void putAdjacentMinesCountsOnBoard();
        int countAdjacentMines(Point point);
        void uncoverAdjacentNonMinePoints(Point uncoveredPoint);
        char digitToChar(int digit);
};

#endif // BOARD_H
