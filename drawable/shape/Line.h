#pragma once

#include "Shape.h"
#include "../../util/Color.h"
#include <sstream>

namespace drawIt {

class Line: public Shape {
    Color color;
    Point points[2];
    public:
        Line(Point x, Point y);
        Line(Point x, Point y, Color c);
        void display() override;
        bool inside(const Point&) override;

        Point getX() {return points[0]; }
        Point getY() {return points[1]; }

        void setX(const Point point) { points[0] = point; }
        void setY(const Point point) { points[1] = point; }

        std::string toString() override {
            std::ostringstream stream;
            stream<<"Line{"<<points[0]<<","<<points[1]<<","<<color<<"}\n";
            return stream.str();
        }
};

}