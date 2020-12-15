#include <iostream>
#include <sstream>
#include "Button.h"
#include "../input/Mouse.h"

Button::Button(const int xPos, const int yPos, 
               const int width, const int height) : 
               Rectangle(xPos, yPos, width, height) {};

Button::Button(const int xPos, const int yPos, 
               const int width, const int height, std::string text) : 
               Rectangle(xPos, yPos, width, height) {
                   this->text = std::make_shared<Text>(Text{text, point});
               };

Button::Button(const Point point,
               const int width, const int height) :
               Rectangle(point, width, height) {};  

Button::Button(const Point point,
               const int width, const int height,
               const std::string text) :
               Rectangle(point, width, height) {
                   this->text = std::make_shared<Text>(Text{text, point});
               };

void Button::display() {
    if(visible) {
        if(mouseHover()) {
            displayRectangle(Color{0.0, 0.0, 0.0});
        } 
        else { displayRectangle(Color{0.64f, 0.63f, 0.63f});}
        if(text != nullptr) {
            text->display();
        }
         mouseClick();
    }
};

bool Button::mouseHover() {
    if(inside(Mouse::getPosition())) {
        return true;
    }
    return false;
}

bool Button::mouseClick() {
    if(mouseHover() && Mouse::leftClicked()) {
        this->action;
        return true;
    } else {
        return false;
    }
}
