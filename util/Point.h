#pragma once
#include <iostream>

namespace drawIt{

    class Point {
        protected:
            int x, y;
        public:
            Point(): x{0}, y{0} {};
            Point(const int x,const int y): x{x}, y{y} {};
            void setX(const int x) { this->x = x; }
            void setY(const int y) { this->y = y; }
            int getX() const { return this->x; }
            int getY() const { return this->y; }
            friend std::ostream& operator<<(std::ostream& os, const Point& x) {
                   os<<"Point{"<<x.getX()<<","<<
                   x.getY()<<"}";
                   return os;
            }
    };

}