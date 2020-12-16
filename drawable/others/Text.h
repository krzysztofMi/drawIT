#pragma once

#include <GL/freeglut.h>
#include <string>
#include "../Drawable.h"
#include "../../util/Point.h"
#include "../../util/Color.h"

class Text: public Drawable {
    private:
        std::string text;
        Point point;
        Color color;
    public:
        Text(std::string text, Point point): 
            text{text}, point{point}, color{Color{0.0, 0.0, 0.0}}{};
        Text(std::string, Point point, Color color): 
            text{text}, point{point}, color{color}{}; 
        void display();
        ~Text(){};

};