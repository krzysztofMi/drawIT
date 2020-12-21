#pragma once

#include "Triangle.h"
#include "../../menu/Toolbar.h"
#include <sstream>

namespace drawIt {
    class BorderTriangle: public Triangle {
        private:
            Color borderColor;
            Color backgroundColor;
        public:
            BorderTriangle(Point x, Point y, Point z)
            : Triangle(x, y, z),
             borderColor{Toolbar::borderColor}, backgroundColor{Toolbar::color} {}

             BorderTriangle(Point x, Point y, Point z, Color backC, Color bordC, bool fill)
            : Triangle(x, y, z),
            backgroundColor{backC}, borderColor{bordC} {
                visible = true;
                this->fill = fill;
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
                stream<<"Triangle{"<<points[0]<<","<<
                points[1]<<","<<
                points[2]<<","<<
                backgroundColor<<","<<
                borderColor<<","<<
                fill<<"}\n";
                return stream.str();
            }
            
    };
}