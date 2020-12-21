#pragma once

#include "Shape.h"
#include <vector> 

namespace drawIt {
    class Triangle : public Shape {
    protected:
        std::vector<Point> point;
        int width, heigth;   
    public:
        bool inside(const Point& point) {};
    };
}