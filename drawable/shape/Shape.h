#pragma once
#include "../Drawable.h"
#include "../../util/Point.h"

namespace drawIt{

class Shape: public Drawable {
    public:
        virtual bool inside(const Point& point) = 0;
        virtual std::string toString() {return "toDo"; }
};

}