#pragma once
#include "Drawable.h"
#include "../../util/Point.h"

class Shape: public Drawable {
    virtual bool inside(const Point& point) = 0;
};