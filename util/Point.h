#pragma once

class Point {
    private:
        int x, y;
    public:
        Point(): x{0}, y{0} {};
        Point(const int x,const int y): x{x}, y{y} {};
        void setX(const int x) { this->x = x; }
        void setY(const int y) { this->y = y; }
        int getX() { return this->x; }
        int getY() { return this->y; }
};