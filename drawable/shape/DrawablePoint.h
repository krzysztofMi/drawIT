#pragma once

#include <GL/freeglut.h>
#include "Shape.h"
#include "../../menu/Toolbar.h"

class DrawablePoint: public Point, public Shape {
    public:
        DrawablePoint(): Point() {};
        DrawablePoint(const int x,const int y): Point(x, y) {};
        DrawablePoint(Point point): Point(point.getX(), point.getY()) {}

        void display() override {
            Color c = Toolbar::color;
            glColor3f(c.getR(), c.getG(), c.getB());
            glBegin(GL_POINTS);
                glPointSize(50);
                glVertex2i(x, y);
            glEnd();
        }

        bool inside(const Point& point) {
            if(point.getX() == x && point.getY() == y) {
                return true;
            } 
            return false;
        }
};