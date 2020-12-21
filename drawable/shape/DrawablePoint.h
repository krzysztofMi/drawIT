#pragma once

#include <GL/freeglut.h>
#include "Shape.h"
#include "../../menu/Toolbar.h"
#include "../../board/Board.h"
namespace drawIt{

class DrawablePoint: public Point, public Shape {
    private:
        Color c;
    public:
        DrawablePoint(): Point(), c{Toolbar::color} {};
        DrawablePoint(const int x,const int y): Point(x, y), c{Toolbar::color} {};
        DrawablePoint(Point point): Point(point.getX(), point.getY()), c{Toolbar::color} {}

        void display() override {
            glColor3f(c.getR(), c.getG(), c.getB());
            glBegin(GL_POINTS);
                glVertex2i(x, Board::screenHeight-y);
            glEnd();
        }

        bool inside(const Point& point) {
            if(point.getX() == x && point.getY() == y) {
                return true;
            } 
            return false;
        }
};

}