#pragma once

class Drawable {
    public:
    virtual ~Drawable() {};
    virtual void display() = 0;
};