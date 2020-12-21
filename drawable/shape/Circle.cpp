#include "Circle.h"
#include "../../menu/Toolbar.h"
#include "../../board/Board.h"
#include <cmath>

namespace drawIt{

    Circle::Circle(const Point point):
        point{point}, radius{0}, 
        color{Toolbar::color}, fill{Toolbar::fill} {}


    void Circle::displayFill() {
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(point.getX(), Board::screenHeight - point.getY());
            for(int i = 0; i < 360; i++)
            {
                float theta = 2.0f * 3.1415926f * float(i) / float(360);
                float x = radius * cosf(theta);
                float y = radius * sinf(theta);
                    glVertex2f(x + point.getX(),  y + (Board::screenHeight - point.getY()));
            }
        glEnd();
    }

    void Circle::displayEmpty() {
        glBegin(GL_LINE_LOOP);
        for(int i = 0; i < 360; i++)
        {
            float theta = 2.0f * 3.1415926f * float(i) / float(360);

            float x = radius * cosf(theta);
            float y = radius * sinf(theta);
            glVertex2f(x + point.getX(), y + (Board::screenHeight - point.getY()));
        }
        glEnd();
    }

    void Circle::display() {
        if(visible) {
            glColor3f(color.getR(), color.getG(), color.getB());
            if(fill) {
                displayFill();
            } else {
                displayEmpty();
            }
        }
    }

    void Circle::setRadiusByDistance(const Point point) {
        int dx = pow(point.getX() - this->point.getX(), 2);
        int dy = pow(point.getY() - this->point.getY(), 2);
        radius = sqrt(dx + dy);
    }
}

