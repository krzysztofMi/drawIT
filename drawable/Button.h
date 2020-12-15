#pragma once
#include <string>
#include <memory>
#include "../util/Color.h"
#include "Rectangle.h"
#include "Text.h"
class Button;

typedef void(*Action)(Button button);

class Button : public Rectangle{
    private:
        std::shared_ptr<Text> text;
        Action action;
    public:
        Button(const int xPos, const int yPos,
               const int width, const int height);
        Button(const int xPos, const int yPos,
               const int width, const int height, std::string text);
        Button(const Point point,
                const int width, const int height);
        Button(const Point point,
                const int width, const int height, std::string text);

        void display() override;
        bool mouseHover();
        bool mouseClick();
        ~Button() {};
};