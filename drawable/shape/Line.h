#pragma once

#include "Shape.h"
#include "../../util/Color.h"

namespace drawIt {

class Line: public Shape {
    Color color;
    Point points[2];
    public:
        Line(Point x, Point y);
        void display() override;
        bool inside(const Point&) override;

        Point getX() {return points[0]; }
        Point getY() {return points[1]; }

        void setX(const Point point) { points[0] = point; }
        void setY(const Point point) { points[1] = point; }
};

}