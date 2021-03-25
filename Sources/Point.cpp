#include "Point.h"

using namespace std;

Point::Point() {
    x = -1;
    y = -1;
}

Point::Point(int aX, int aY) {
    x = aX;
    y = aY;
}

void Point::randomize(int xMin, int xMax, int yMin, int yMax) {
    x = getRandNum(xMin, xMax);
    y = getRandNum(yMin, yMax);
}

bool Point::cmp(Point point) {
    if (x == point.x && y == point.y) {
        return true;
    }
    return false;
}

int Point::getRandNum(int min, int max) {
    int randNum = rand() % (max - min + 1) + min;
    return randNum;
}
