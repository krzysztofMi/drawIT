#pragma once

#include "Tool.h"
#include "../shape/BorderCircle.h"
#include "../../board/Board.h"

namespace drawIt{

    class CircleTool: public Tool {
        private:
            std::shared_ptr<BorderCircle> circle;
        public:
        void draw(Canvas& canvas){
            if(insideCanvas(canvas)) {
                if(Mouse::leftClicked()) {
                    Point mousePosition = Mouse::getPosition();
                    if(circle == nullptr) {
                        mousePosition.setY(mousePosition.getY());
                        circle = std::make_shared<BorderCircle>(
                            mousePosition);
                        canvas.draw(circle);
                    } else {
                        canvas.removeLast();
                        circle->setRadiusByDistance(mousePosition);
                        canvas.draw(circle);
                    }
                } else {
                    circle = nullptr;
                }    
            }
        }
    };

}