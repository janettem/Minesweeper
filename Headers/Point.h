#ifndef POINT_H
#define POINT_H

#include <stdlib.h>

class Point {
    public:
        int x, y;
        Point();
        Point(int aX, int aY);
        void randomize(int xMin, int xMax, int yMin, int yMax);
        bool cmp(Point point);
    private:
        int getRandNum(int min, int max);
};

#endif // POINT_H
