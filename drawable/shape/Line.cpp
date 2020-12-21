#include "Line.h"
#include "../../menu/Toolbar.h"
#include <GL/freeglut.h>
#include "../../board/Board.h"

namespace drawIt{

    Line::Line(Point x, Point y):
         points{x, y}, color{Toolbar::color} {}

    void Line::display() {
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_LINES);
            glVertex2f(points[0].getX(), Board::screenHeight-points[0].getY());
            glVertex2f(points[1].getX(), Board::screenHeight-points[1].getY());
        glEnd();
    }

    bool Line::inside(const Point& point) {
            return false;
    }
}