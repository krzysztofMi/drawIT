#pragma once

#include <GL/gl.h>
#include "Shape.h"
#include "../../util/Point.h"
#include "../../util/Color.h"

namespace drawIt {

class Rectangle : public Shape {
    protected:
        Point point;
        Color color;
        int width, height;
        bool fill;
        void displayEmpty();
        void displayFill();
    public:
        Rectangle(const int xPos, const int yPos,
               const int width, const int height);
        Rectangle(const Point point,
                const int width, const int height);
        Rectangle(const Point point,
                const int width, const int height,
                Color color, bool fill);

        bool inside(const Point& point) override;
        void display() override;
        
        void setColor(const Color& color) {this->color = color; }
        void setWidth(const int width) {this->width = width;}
        void setHeigth(const int height) {this->height = height;}
        Point getPoint() { return this->point; }
        ~Rectangle(){};
};

}