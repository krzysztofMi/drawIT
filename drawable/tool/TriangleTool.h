#pragma once

#include "Tool.h"
#include "../shape/Triangle.h"

namespace drawIt{

class TriangleTool: public Tool {
    private:
        std::shared_ptr<Triangle> triangle;
    public:
        void draw(Canvas& canvas) {
            if(insideCanvas(canvas)) {
                if(Mouse::leftClicked()) {
                    Point mousePosition = Mouse::getPosition();
                    if(triangle == nullptr) {
                        triangle = std::make_shared<Triangle>(
                            mousePosition, mousePosition, mousePosition);
                        canvas.draw(triangle);
                    } else {
                        canvas.removeLast();
                        triangle->setByDistance(mousePosition);
                        canvas.draw(triangle);
                    }
                } else {
                    triangle = nullptr;
                }    
            }    
        }
};

}