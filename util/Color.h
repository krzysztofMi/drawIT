#pragma once

#include <sstream>

namespace drawIt{

class Color {
    private: 
        float r, g, b;
    public:
        Color(const float r, const float g, const float b);
        void setColor(const float r, const float g, const float b);

        float getR() { return this->r; }
        float getG() { return this->g; }
        float getB() { return this->b; }

        static Color red() { return Color{1.0, 0.0, 0.0}; }
        static Color green() { return  Color{0.0, 1.0, 0.0};}
        static Color blue() { return  Color{0.0, 0.0, 1.0};}

        friend std::ostream& operator<<(std::ostream& os, const Color& x) {
                   os<<"Color{"<<x.r<<","<<
                   x.g<<","<<
                   x.b<<"}";
                   return os;
        }
};

}