#pragma once
#include <string>
#include <memory>
#include <functional>
#include "../util/Color.h"
#include "Rectangle.h"
#include "Text.h"
class Button;

class Button : public Rectangle{
    private:
        std::shared_ptr<Text> text;
        std::function<void()> action;
    public:
        Button(const int xPos, const int yPos,
               const int width, const int height, std::function<void()>  action);
        Button(const int xPos, const int yPos,
               const int width, const int height, std::string text, std::function<void()>  action);
        Button(const Point point,
                const int width, const int height, std::function<void()>  action);
        Button(const Point point,
                const int width, const int height, std::string text, std::function<void()> action);
        void display() override;
        bool mouseHover();
        bool mouseClick();
        bool callAction();
        ~Button() {};
};