#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(int aWidth, int aHeight, int aMines) {
    setWidth(aWidth);
    setHeight(aHeight);
    setMines(aMines);
    setBoard();
}

void Board::setWidth(int aWidth) {
    if (aWidth >= 1) {
        width = aWidth;
    } else {
        width = 1;
    }
}

void Board::setHeight(int aHeight) {
    if (aHeight >= 1) {
        height = aHeight;
    } else {
        height = 1;
    }
}

void Board::setMines(int aMines) {
    if (aMines >= 0 && aMines <= width * height) {
        mines = aMines;
    } else {
        mines = 0;
    }
}

void Board::setBoard() {
    board = new Cell *[height];
    for (int i = 0; i < height; i++) {
        board[i] = new Cell[width];
    }
}

/*
void printBoard(Cell **board) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j].getState == "uncovered") {
                cout << board[i][j].getValue;
            } else if (board[i][j].getState == "covered") {
                cout << ' ';
            } else {
                cout << '<';
            }
        }
        cout << endl;
    }
}
*/
