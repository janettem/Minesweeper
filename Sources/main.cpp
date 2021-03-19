#include "minesweeper.h"

using namespace std;

int main() {
    Point point(5, 5);
    // string state;
    srand(time(NULL));
    BeginnerBoard board;
    board.printBoard();

    /*
    cout << endl << "X [0-"<< board.getWidth() - 1 << "]: ";
    cin >> point.x;
    cout << "Y [0-"<< board.getHeight() - 1 << "]: ";
    cin >> point.y;
    cout << "Uncovered or flagged [uncovered/flagged]: ";
    getline(cin, state);
    */

    board.getBoard()[point.y][point.x].setState(UNCOVERED);
    board.putValuesOnBoard(point);
    board.uncoverAdjacentNonMinedPoints(point);
    cout << endl;
    board.printBoard();
    return 0;
}
