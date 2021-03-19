#include "CustomBoard.h"

using namespace std;

CustomBoard::CustomBoard(int aWidth, int aHeight, int aMines) {
    setWidth(aWidth);
    setHeight(aHeight);
    setMines(aMines);
    setBoard();
}

void CustomBoard::setWidth(int aWidth) {
    if (aWidth >= 1) {
        width = aWidth;
    } else {
        width = 1;
    }
}

void CustomBoard::setHeight(int aHeight) {
    if (aHeight >= 1) {
        height = aHeight;
    } else {
        height = 1;
    }
}

void CustomBoard::setMines(int aMines) {
    if (aMines >= 0 && aMines <= width * height) {
        mines = aMines;
    } else {
        mines = 0;
    }
}

void CustomBoard::putValuesOnBoard(Point firstUncoveredPoint) {
    putMinesOnBoard(firstUncoveredPoint);
    putAdjacentMinesCountsOnBoard();
}

void CustomBoard::uncoverAdjacentNonMinedPoints(Point uncoveredPoint) {
    // TODO
}

bool CustomBoard::isOnBoard(Point point) {
    if (point.y >= 0 && point.y < height &&
    point.x >= 0 && point.x < width) {
        return true;
    }
    return false;
}

void CustomBoard::printBoard() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j].getState() == UNCOVERED) {
                cout << board[i][j].getValue();
            } else if (board[i][j].getState() == COVERED) {
                cout << '.';
            } else {
                cout << 'X';
            }
        }
        cout << endl;
    }
}

void CustomBoard::setBoard() {
    board = new Cell *[height];
    for (int i = 0; i < height; i++) {
        board[i] = new Cell[width];
    }
}

void CustomBoard::putMinesOnBoard(Point firstUncoveredPoint) {
    Point index;
    for (int i = 0; i < mines;) {
        index.randomize(0, width - 1, 0, height - 1);
        if (!index.cmp(firstUncoveredPoint) &&
        board[index.y][index.x].getValue() != MINE) {
            board[index.y][index.x].setValue(MINE);
            i++;
        }
    }
}

void CustomBoard::putAdjacentMinesCountsOnBoard() {
    int adjacentMines;
    Point point;
    for (point.y = 0; point.y < height; point.y++) {
        for (point.x = 0; point.x < width; point.x++) {
            if (board[point.y][point.x].getValue() != MINE) {
                adjacentMines = countAdjacentMines(point);
                board[point.y][point.x].setValue(digitToChar(adjacentMines));
            }
        }
    }
}

int CustomBoard::countAdjacentMines(Point point) {
    int adjacentMines = 0;
    Point adjacentPoint;
    for (adjacentPoint.y = point.y - 1; adjacentPoint.y <= point.y + 1;
    adjacentPoint.y++) {
        for (adjacentPoint.x = point.x - 1; adjacentPoint.x <= point.x + 1;
        adjacentPoint.x++) {
            if (isOnBoard(adjacentPoint) &&
            board[adjacentPoint.y][adjacentPoint.x].getValue() == MINE) {
                adjacentMines++;
            }
        }
    }
    return adjacentMines;
}

char CustomBoard::digitToChar(int digit) {
    char c = '0' + digit;
    return c;
}
