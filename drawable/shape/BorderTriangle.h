#pragma once

#include "Triangle.h"
#include "../../menu/Toolbar.h"

namespace drawIt {
    class BorderTriangle: public Triangle {
        private:
            Color borderColor;
            Color backgroundColor;
        public:
            BorderTriangle(Point x, Point y, Point z)
            : Triangle(x, y, z),
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