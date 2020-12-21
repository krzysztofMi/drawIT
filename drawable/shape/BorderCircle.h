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
             BorderCircle(Point x, float r, Color bgColor, Color brColor, bool fill): 
                Circle(x, r), backgroundColor{bgColor}, borderColor{brColor} {
                    this->fill = fill;
                    this->visible = true;
                }
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
            std::string toString() override{
                std::ostringstream stream;
                stream<<"Circle{"<<point<<","<<
                radius<<","<<
                backgroundColor<<","<<
                borderColor<<","<<fill<<"}\n";
                return stream.str();
            }
    };
}