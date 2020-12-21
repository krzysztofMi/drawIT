#include "Rectangle.h"
#include "../../menu/Toolbar.h"
#include "../../board/Board.h"

namespace drawIt{

Rectangle::Rectangle(const int xPos, const int yPos, 
               const int width, const int height) : 
               point{xPos, yPos}, width{width}, height{height}, 
               color{Toolbar::color}, fill{Toolbar::fill} {};

Rectangle::Rectangle(const Point point,
               const int width, const int height) :
               point{ point }, width{width}, height{height},
               color{Toolbar::color}, fill{Toolbar::fill} {};  

Rectangle::Rectangle(const Point point,
               const int width, const int height, 
               const Color color, const bool fill) :
               point{ point }, width{width}, height{height},
               color{color}, fill{fill} {};  

bool Rectangle::inside(const Point &point){
    if (point.getX() >= this->point.getX()) {
		if (point.getY() >= this->point.getY()) {
			if (point.getX() < this->point.getX() + width) {
				if (point.getY() < this->point.getY() + height) {
					return true;
				}
			}
		}
	}
	return false;
}

void Rectangle::displayEmpty() {
    glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_LINE_LOOP);
            glVertex2f(point.getX(),       Board::screenHeight-point.getY());
            glVertex2f(point.getX()+width, Board::screenHeight-point.getY());
            glVertex2f(point.getX()+width, Board::screenHeight-point.getY()-height);
            glVertex2f(point.getX(),       Board::screenHeight-point.getY()-height);
    glEnd();
}

void Rectangle::displayFill() {
     glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_QUADS);
            glVertex2f(point.getX(),       Board::screenHeight-point.getY());
            glVertex2f(point.getX()+width, Board::screenHeight-point.getY());
            glVertex2f(point.getX()+width, Board::screenHeight-point.getY()-height);
            glVertex2f(point.getX(),       Board::screenHeight-point.getY()-height);
    glEnd();
}

void Rectangle::display() {
    if(visible) {
        if(fill) {
            displayFill();
        } else {
            displayEmpty();
        }
    }
}

}