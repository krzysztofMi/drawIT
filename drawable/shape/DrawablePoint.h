#pragma once

#include <GL/freeglut.h>
#include "Shape.h"
#include "../../menu/Toolbar.h"
#include "../../board/Board.h"
namespace drawIt{

class DrawablePoint: public Point, public Shape {
    public:
        DrawablePoint(): Point() {};
        DrawablePoint(const int x,const int y): Point(x, y) {};
        DrawablePoint(Point point): Point(point.getX(), point.getY()) {}

        void display() override {
            Color c = Toolbar::color;
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