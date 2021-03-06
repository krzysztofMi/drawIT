#include <iostream>
#include <sstream>
#include "Button.h"
#include "../../input/Mouse.h"
namespace drawIt{

Button::Button(const int xPos, const int yPos, 
               const int width, const int height, std::function<void()>  action) : 
               Rectangle(xPos, yPos, width, height), action{action},
               hoverColor{Color{0.1, 0.2, 0.3}}, backgroundColor{Color{0.5, 0.6, 0.7}} {};

Button::Button(const int xPos, const int yPos, 
               const int width, const int height, std::string text, std::function<void()>  action) : 
               Rectangle(xPos, yPos, width, height), action{action},
               hoverColor{Color{0.1, 0.2, 0.3}}, backgroundColor{Color{0.5, 0.6, 0.7}}  {
                   this->text = std::make_shared<Text>(Text{text, Point{xPos, yPos+height}});
               };

Button::Button(const Point point,
               const int width, const int height, std::function<void()>  action) :
               Rectangle(point, width, height), action{action},
               hoverColor{Color{0.1, 0.2, 0.3}}, backgroundColor{Color{0.5, 0.6, 0.7}}  {};  

Button::Button(const Point point,
               const int width, const int height,
               const std::string text, std::function<void()>  action) :
               Rectangle(point, width, height), action{action},
               hoverColor{Color{0.1, 0.2, 0.3}}, backgroundColor{Color{0.5, 0.6, 0.7}}  {
                   this->text = std::make_shared<Text>(Text{text, 
                        Point{point.getX(), point.getY() + height}});
               };

void Button::display() {
    if(visible) {
        if(mouseHover()) {
            color = hoverColor;
            displayFill();
            mouseClick();
        } 
        else { 
            color = backgroundColor;
            displayFill();
        }
        if(text != nullptr) {
            text->display();
        }
    }
};

bool Button::mouseHover() {
    if(inside(Mouse::getPosition())) {
        return true;
    }
    return false;
}

bool Button::mouseClick() {
    if(Mouse::leftClicked()) {
        callAction();
        return true;
    }
    return false;
}

bool Button::callAction() {
    if(action != nullptr) {
        this->action();
        return true;
    }
    return false;
}

}