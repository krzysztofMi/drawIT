#pragma once

#include "Tool.h"
#include "../shape/BorderTriangle.h"

namespace drawIt{

class TriangleTool: public Tool {
    private:
        std::shared_ptr<BorderTriangle> triangle;
    public:
        void draw(Canvas& canvas) {
            if(insideCanvas(canvas)) {
                if(Mouse::leftClicked()) {
                    Point mousePosition = Mouse::getPosition();
                    if(triangle == nullptr) {
                        triangle = std::make_shared<BorderTriangle>(
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