#pragma once

#include "Tool.h"

class Pencil: public Tool {
    public:
        void draw(Canvas& canvas) override;    
};