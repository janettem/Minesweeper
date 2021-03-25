#include "Console.h"

using namespace std;

void Console::clearLine(int n) {
    for (int i = 0; i < n; i++) {
        cout << strCursorUp << strClearLine << "\r";
    }
}

void Console::setColor(int color) {
    if (isColor(color)) {
        cout << "\033[" << red << "m";
    }
}

void Console::reset() {
    cout << strReset;
}

bool Console::isColor(int color) {
    if (color >= black && color <= white) {
        return true;
    }
    return false;
}
