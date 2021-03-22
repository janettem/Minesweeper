#include "Board.h"

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

void Board::putValuesOnBoard(Point firstUncoveredPoint) {
    putMinesOnBoard(firstUncoveredPoint);
    putAdjacentMinesCountsOnBoard();
}

bool Board::hasCoveredNonMinePoints() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j].getState() == COVERED &&
            board[i][j].getValue() != MINE) {
                return true;
            }
        }
    }
    return false;
}

void Board::playTurn(Point point, int state) {
    board[point.y][point.x].setState(state);
    if (state == UNCOVERED && board[point.y][point.x].getValue() == '0') {
        uncoverAdjacentNonMinePoints(point);
    }
}

void Board::printBoard() {
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

void Board::setBoard() {
    board = new Cell *[height];
    for (int i = 0; i < height; i++) {
        board[i] = new Cell[width];
    }
}

void Board::putMinesOnBoard(Point firstUncoveredPoint) {
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

void Board::putAdjacentMinesCountsOnBoard() {
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

int Board::countAdjacentMines(Point point) {
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

void Board::uncoverAdjacentNonMinePoints(Point uncoveredPoint) {
    Point adjacentPoint;
    for (adjacentPoint.y = uncoveredPoint.y - 1;
    adjacentPoint.y <= uncoveredPoint.y + 1; adjacentPoint.y++) {
        for (adjacentPoint.x = uncoveredPoint.x - 1;
        adjacentPoint.x <= uncoveredPoint.x + 1; adjacentPoint.x++) {
            if (isOnBoard(adjacentPoint) &&
            board[adjacentPoint.y][adjacentPoint.x].getState() == COVERED) {
                board[adjacentPoint.y][adjacentPoint.x].setState(UNCOVERED);
                if (board[adjacentPoint.y][adjacentPoint.x].getValue() == '0') {
                    uncoverAdjacentNonMinePoints(adjacentPoint);
                }
            }
        }
    }
}

bool Board::isOnBoard(Point point) {
    if (point.y >= 0 && point.y < height &&
    point.x >= 0 && point.x < width) {
        return true;
    }
    return false;
}

char Board::digitToChar(int digit) {
    char c = '0' + digit;
    return c;
}
