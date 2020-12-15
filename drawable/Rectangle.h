#pragma once

#include <GL/gl.h>
#include "interface/Shape.h"
#include "../util/Point.h"
#include "../util/Color.h"

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

        ~Rectangle(){};
};