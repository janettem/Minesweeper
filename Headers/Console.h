#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>

class Console {
    public:
        const std::string strCursorUp = "\033[A";
        const std::string strClearLine = "\033[2K";
        const std::string strReset = "\033[0m";
        const int black = 30;
        const int red = 31;
        const int green = 32;
        const int yellow = 33;
        const int blue = 34;
        const int magenta = 35;
        const int cyan = 36;
        const int white = 37;
        void clearLine(int n);
        void setColor(int color);
        void reset();
    private:
        bool isColor(int color);
};

#endif // CONSOLE_H
