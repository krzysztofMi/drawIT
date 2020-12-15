#pragma once
#include <string>
#include <GL/gl.h>
#include <memory>
#include "../util/Color.h"
#include "interface/Drawable.h"
#include "../util/Point.h"
#include "Text.h"
class Button;

typedef void(*Action)(Button button);

class Button : public Drawable{
    private:
        Point point;
        int width, height;
        std::shared_ptr<Text> text;
        Action callback;
        Color color;
    
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
        std::string toString();
        ~Button() {};
};