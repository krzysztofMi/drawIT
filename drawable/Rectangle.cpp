#include "Rectangle.h"
#include "../container/Toolbar.h"

Rectangle::Rectangle(const int xPos, const int yPos, 
               const int width, const int height) : 
               point{xPos, yPos}, width{width}, height{height} {};

Rectangle::Rectangle(const Point point,
               const int width, const int height) :
               point{ point }, width{width}, height{height} {};  


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

void Rectangle::displayRectangle(Color color) {
    glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_QUADS);
            glVertex2f(point.getX(),       point.getY());
            glVertex2f(point.getX()+width, point.getY());
            glVertex2f(point.getX()+width, point.getY()+height);
            glVertex2f(point.getX(),       point.getY()+height);
    glEnd();
}

void Rectangle::display() {
    if(visible) {
        displayRectangle(Toolbar::color);
    }
}