#pragma once

#include "Tool.h"
#include "../shape/Triangle.h"

namespace drawIt{

class TraiangleTool: public Tool {
    private:
        std::shared_ptr<Triangle> traiangle;
};

}