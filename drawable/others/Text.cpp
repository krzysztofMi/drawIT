#include "Text.h"

#include <iostream>
#include "../../board/Board.h"
namespace drawIt{

void Text::display() {
    if(visible) {
        glColor3f(0.0f, 0.0f, 0.0f);
        glRasterPos2f(point.getX(), Board::screenHeight - point.getY());
        auto text = (const unsigned char *)this->text.c_str();
        glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, text);
    }
}

}