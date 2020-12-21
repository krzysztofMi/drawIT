#pragma once

#include "Shape.h"
#include "../../util/Color.h"

namespace drawIt {

class Circle: public Shape {
    protected:
        Point point;
        float radius;
        Color color;
        bool fill;
        void displayFill();
        void displayEmpty();
    public: 
        Circle(const Point point);
        void setRadius(const float radious) { this->radius = radious; }
        void setRadiusByDistance(const Point point);
        void display() override;
        bool inside(const Point& point) { return true; }      
};

}