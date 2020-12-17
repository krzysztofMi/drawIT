#pragma once

#include <GL/gl.h>
#include "Shape.h"
#include "../../util/Point.h"
#include "../../util/Color.h"

namespace drawIt {

class Rectangle : public Shape {
    protected:
        Point point;
        int width, height;
        
        void displayRectangle(Color color);
    public:
        Rectangle(const int xPos, const int yPos,
               const int width, const int height);
        Rectangle(const Point point,
                const int width, const int height);

        bool inside(const Point& point) override;
        void display() override;

        void setWidth(const int width) {this->width = width;}
        void setHeigth(const int height) {this->height = height;}
        Point getPoint() { return this->point; }
        ~Rectangle(){};
};

}