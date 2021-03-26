#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <iostream>
#include <climits>
#include "Board.h"
#include "Console.h"

class UserInput {
    public:
        UserInput();
        void setUserInput(Board board);
        Point getPoint() {return point;}
        int getState() {return state;}
    private:
        Point point;
        int state;
        Cell cell;
        Console console;
        const int intMaxLen = 11;
        void setPoint(Board board);
        void setPointX(int max);
        void setPointY(int max);
        void setState(Cell **board);
        int strToInt(std::string str);
        bool isNum(std::string str, int len);
};

#endif // USER_INPUT_H
