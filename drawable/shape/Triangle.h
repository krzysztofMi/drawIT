#pragma once

#include "Shape.h"
#include "../../util/Color.h"
#include <array> 

namespace drawIt {

    class Triangle : public Shape {
    protected:
        Color color;
        bool fill;
        std::array<Point, 3> points;
        int width, heigth;   
        void displayEmpty();
        void displayFill();
    public:
        Triangle(Point x, Point y, Point z);

        //seting triangle coordinates by calculte distance
        //beetwen points[0] and pointX
        void setByDistance(const Point x) {
            width = points[0].getX() - x.getX();
            heigth = points[0].getY() - x.getY();
            points[1].setX(points[0].getX() - width);
            points[2].setY(points[0].getY() - width);
            points[2].setX(points[0].getX() - width/2);
        }

        void setX(const Point x) {points[0] = x; }
        void setY(const Point y) {points[1] = y; }
        void setZ(const Point z) {points[2] = z; }

        bool inside(const Point& point) {return true;};
        void display() override;
    };
}