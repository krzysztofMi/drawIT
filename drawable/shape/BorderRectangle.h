#pragma once

#include "Rectangle.h"
#include "../../menu/Toolbar.h"

namespace drawIt {
    class BorderRectangle: public Rectangle {
        private:
            Color borderColor;
            Color backgroundColor;
        public:
            BorderRectangle(Point point, int widht, int height)
            : Rectangle(point, width, height),
             borderColor{Toolbar::borderColor}, backgroundColor{Toolbar::color} {}

             void display() override {
                if(visible) {
                    if(fill) {
                        color = backgroundColor;
                        displayFill();
                        color = borderColor;
                        displayEmpty();
                    } else {
                        color = borderColor;
                        displayEmpty();
                    }
                }
             }
    };
}