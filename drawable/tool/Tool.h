#pragma once

#include "../../board/Canvas.h"
#include "../../input/Mouse.h"

class Tool {
    public:
        virtual ~Tool() {}
        virtual void draw(Canvas& canvas) = 0;

        virtual bool insideCanvas(Canvas& canvas) {
            return canvas.inside(Mouse::getPosition());
        }
};