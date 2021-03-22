#include "minesweeper.h"

using namespace std;

int getState() {
    int state;
    cout << "1. uncover or 2. flag/unflag [1/2]: ";
    cin >> state;
    return state;
}

void setPoint(Point &point, Board board) {
    cout << endl << "X [0-"<< board.getWidth() - 1 << "]: ";
    cin >> point.x;
    cout << "Y [0-"<< board.getHeight() - 1 << "]: ";
    cin >> point.y;
}

int main() {
    srand(time(NULL));
    Board board(9, 9, 10);
    Point point;
    int state;
    board.printBoard();
    setPoint(point, board);
    state = getState();
    if (state == FLAGGED &&
    board.getBoard()[point.y][point.x].getState() == FLAGGED) {
        state = COVERED;
    }
    board.putValuesOnBoard(point);
    board.playTurn(point, state);
    cout << endl;
    board.printBoard();
    while ((state == FLAGGED  ||
    board.getBoard()[point.y][point.x].getValue() != MINE) &&
    board.hasCoveredNonMinePoints()) {
        setPoint(point, board);
        state = getState();
        if (state == FLAGGED &&
        board.getBoard()[point.y][point.x].getState() == FLAGGED) {
            state = COVERED;
        }
        board.playTurn(point, state);
        cout << endl;
        board.printBoard();
    }
    return 0;
}
