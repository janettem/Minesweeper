#include "minesweeper.h"

using namespace std;

int main() {
    srand(time(NULL));
    UserInput userInput;
    Board board(userInput.getWidth(), userInput.getHeight(),
    userInput.getMines());
    Cell cell;
    Console console;
    bool firstUncoveredPoint = true;
    console.clearLine(1);
    if (userInput.getLevel() == userInput.custom) {
        console.clearLine(3);
    }
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
