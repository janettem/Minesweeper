#include "minesweeper.h"

using namespace std;

int main() {
    srand(time(NULL));
    Board board(9, 9, 10);
    Cell cell;
    Console console;
    UserInput userInput;
    bool firstUncoveredPoint = true;
    while ((firstUncoveredPoint || (userInput.getState() != cell.uncovered ||
    board.getBoard()[userInput.getPoint().y][userInput.getPoint().x].getValue() != cell.mine) &&
    board.hasCoveredNonMinePoints())) {
        board.printBoard(userInput.getPoint());
        userInput.setUserInput(board);
        if (firstUncoveredPoint && userInput.getState() == cell.uncovered) {
            board.putValuesOnBoard(userInput.getPoint());
            firstUncoveredPoint = false;
        }
        board.playTurn(userInput.getPoint(), userInput.getState());
        console.clearLine(board.getHeight() + 4);
    }
    board.printBoardMines(userInput.getPoint());
    return 0;
}
