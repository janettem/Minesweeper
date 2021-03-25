#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <iostream>
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
        void setPoint(Board board);
        void setPointX(int max);
        void setPointY(int max);
        void setState(Cell **board);
};

#endif // USER_INPUT_H
