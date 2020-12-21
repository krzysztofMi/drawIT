#include "Triangle.h"
#include "../../menu/Toolbar.h"
#include "../../board/Board.h"

namespace drawIt {

    Triangle::Triangle(Point x, Point y, Point z) 
    : points{x, y, z}, color{Toolbar::color}, fill{Toolbar::fill} { }

    void Triangle::displayEmpty() {
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_LINE_LOOP);
            glVertex2f(points[0].getX(), Board::screenHeight - points[0].getY());
            glVertex2f(points[1].getX(), Board::screenHeight - points[1].getY());
            glVertex2f(points[2].getX(), Board::screenHeight - points[2].getY());
        glEnd();
    }

    void Triangle::displayFill() {
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_TRIANGLES);
            glVertex2f(points[0].getX(), Board::screenHeight - points[0].getY());
            glVertex2f(points[1].getX(), Board::screenHeight - points[1].getY());
            glVertex2f(points[2].getX(), Board::screenHeight - points[2].getY());
        glEnd();
    }

    void Triangle::display() {
        if(visible) {
            if(fill) {
                displayFill();
            } else {
                displayEmpty();
            }
        }
    }
}