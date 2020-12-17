#pragma once

#include "Tool.h"
namespace drawIt{

class Pencil: public Tool {
    public:
        void draw(Canvas& canvas) override;    
};

}