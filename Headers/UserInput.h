#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <iostream>
#include <climits>
#include "Board.h"
#include "Console.h"

class UserInput {
    public:
        const int beginner = 0;
        const int intermediate = 1;
        const int expert = 2;
        const int custom = 3;
        UserInput();
        void setUserInput(Board board);
        int getLevel() {return level;}
        int getWidth() {return width;}
        int getHeight() {return height;}
        int getMines() {return mines;}
        Point getPoint() {return point;}
        int getState() {return state;}
    private:
        int level, width, height, mines, state;
        Point point;
        Cell cell;
        Console console;
        const int intMaxLen = 11;
        void setBoard();
        void setLevel(int aWidth, int aHeight, int aMines);
        void setCustomLevel();
        void setWidth();
        void setHeight();
        void setMines(int max);
        void setPoint(Board board);
        void setPointX(int max);
        void setPointY(int max);
        void setState(Cell **board);
        bool isLevel(int level);
        int strToInt(std::string str);
        bool isNum(std::string str, int len);
};

#endif // USER_INPUT_H
