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
            BorderRectangle(Point point, int widht, int height, 
            Color brColor, Color bgColor, bool fill)
            : Rectangle(point, width, height),
             borderColor{borderColor}, backgroundColor{backgroundColor}{
                 this->fill = fill;
                 visible = true;
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

             std::string toString() override {
                 std::ostringstream stream;
                 stream<<"Rectangle{"<<
                 point<<","<<
                 width<<","<<
                 height<<","<<
                 backgroundColor<<","<<
                 borderColor<<","<<
                 fill<<"}\n";
                 return stream.str();
             }
    };
}