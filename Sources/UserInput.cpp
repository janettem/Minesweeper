#include "UserInput.h"

using namespace std;

UserInput::UserInput() {
    state = 0;
    setBoard();
}

void UserInput::setUserInput(Board board) {
    bool uncoverFlaggedPoint = true;
    cout << endl;
    while (uncoverFlaggedPoint) {
        setPoint(board);
        setState(board.getBoard());
        if (state != cell.uncovered ||
        board.getBoard()[point.y][point.x].getState() != cell.flagged) {
            uncoverFlaggedPoint = false;
        } else {
            console.clearLine(3);
        }
    }
}

void UserInput::setBoard() {
    bool validInput = false;
    string input;
    while (!validInput) {
        cout << "1. beginner, 2. intermediate, 3. expert or 4. custom [1-4]: ";
        getline(cin, input);
        level = strToInt(input) - 1;
        if (isLevel(level)) {
            validInput = true;
        } else {
            console.clearLine(1);
        }
    }
    if (level == beginner) {
        setLevel(9, 9, 10);
    } else if (level == intermediate) {
        setLevel(16, 16, 40);
    } else if (level == expert) {
        setLevel(30, 16, 99);
    } else {
        setCustomLevel();
    }
}

void UserInput::setLevel(int aWidth, int aHeight, int aMines) {
    width = aWidth;
    height = aHeight;
    mines = aMines;
}

void UserInput::setCustomLevel() {
    setWidth();
    setHeight();
    setMines(width * height - 1);
}

void UserInput::setWidth() {
    bool validInput = false;
    string input;
    while (!validInput) {
        cout << "Width [8-99]: ";
        getline(cin, input);
        width = strToInt(input);
        if (width >= 8 && width <= 99) {
            validInput = true;
        } else {
            console.clearLine(1);
        }
    }
}

void UserInput::setHeight() {
    bool validInput = false;
    string input;
    while (!validInput) {
        cout << "Height [1-99]: ";
        getline(cin, input);
        height = strToInt(input);
        if (height >= 1 && height <= 99) {
            validInput = true;
        } else {
            console.clearLine(1);
        }
    }
}

void UserInput::setMines(int max) {
    bool validInput = false;
    string input;
    while (!validInput) {
        cout << "Mines [1-" << max << "]: ";
        getline(cin, input);
        mines = strToInt(input);
        if (mines >= 1 && mines <= max) {
            validInput = true;
        } else {
            console.clearLine(1);
        }
    }
}

void UserInput::setPoint(Board board) {
    bool uncoveredPoint = true;
    while (uncoveredPoint) {
        setPointX(board.getWidth());
        setPointY(board.getHeight());
        if (board.getBoard()[point.y][point.x].getState() != cell.uncovered) {
            uncoveredPoint = false;
        } else {
            console.clearLine(2);
        }
    }
}

void UserInput::setPointX(int max) {
    bool validInput = false;
    string input;
    while (!validInput) {
        cout << "X [1-" << max << "]: ";
        getline(cin, input);
        point.x = strToInt(input);
        if (point.x >= 1 && point.x <= max) {
            validInput = true;
        } else {
            console.clearLine(1);
        }
    }
    point.x--;
}

void UserInput::setPointY(int max) {
    bool validInput = false;
    string input;
    while (!validInput) {
        cout << "Y [1-" << max << "]: ";
        getline(cin, input);
        point.y = strToInt(input);
        if (point.y >= 1 && point.y <= max) {
            validInput = true;
        } else {
            console.clearLine(1);
        }
    }
    point.y--;
}

void UserInput::setState(Cell **board) {
    bool validInput = false;
    string input;
    while (!validInput) {
        cout << "1. uncover or 2. flag/unflag [1/2]: ";
        getline(cin, input);
        state = strToInt(input);
        if (state == cell.uncovered || state == cell.flagged) {
            validInput = true;
        } else {
            console.clearLine(1);
        }
    }
    if (state == cell.flagged &&
    board[point.y][point.x].getState() == cell.flagged) {
        state = cell.covered;
    }
}

bool UserInput::isLevel(int level) {
    if (level == beginner ||
    level == intermediate ||
    level == expert ||
    level == custom) {
        return true;
    }
    return false;
}

int UserInput::strToInt(string str) {
    long long num;
    int len = str.length();
    if (len >= 1 && len <= intMaxLen && isNum(str, len)) {
        num = stoll(str);
        if (num >= INT_MIN && num <= INT_MAX) {
            return num;
        }
    }
    return 0;
}

bool UserInput::isNum(string str, int len) {
    int i = 0;
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }
    for (; i < len; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
