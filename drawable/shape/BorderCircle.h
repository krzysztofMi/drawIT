#pragma once

#include "Circle.h"
#include "../../menu/Toolbar.h"

namespace drawIt {
    class BorderCircle: public Circle {
        private:
            Color borderColor;
            Color backgroundColor;
        public:
            BorderCircle(Point x)
            : Circle(x),
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