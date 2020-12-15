#include <iostream>
#include <sstream>
#include "Button.h"

Button::Button(const int xPos, const int yPos, 
               const int width, const int height) : 
               point{xPos, yPos}, width{width}, height{height}, 
               color{0.64f, 0.63f, 0.63f} {};

Button::Button(const int xPos, const int yPos, 
               const int width, const int height, std::string text) : 
               point{xPos, yPos}, width{width}, height{height}, 
               color{0.64f, 0.63f, 0.63f}{
                   this->text = std::make_shared<Text>(Text{text, point});
               };

Button::Button(const Point point,
               const int width, const int height) :
               point{ point }, width{width}, height{height}, 
               color{0.64f, 0.63f, 0.63f} {};  

Button::Button(const Point point,
               const int width, const int height,
               const std::string text) :
               point{ point }, width{width}, height{height}, 
               color{0.64f, 0.63f, 0.63f} {
                   this->text = std::make_shared<Text>(Text{text, point});
               };

void Button::display() {
    glColor3f(color.getR(), color.getG(), color.getB());
    glBegin(GL_QUADS);
        glVertex2f(point.getX(),       point.getY());
        glVertex2f(point.getX()+width, point.getY());
        glVertex2f(point.getX()+width, point.getY()+height);
        glVertex2f(point.getX(),       point.getY()+height);
    glEnd();
    if(text != nullptr) {
        text->display();
    }
};

std::string Button::toString(){
    std::ostringstream oss;
    oss << this->point.getX() << " " << this->point.getY() << "\n";
    return oss.str();
}