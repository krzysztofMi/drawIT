#pragma once

#include "Tool.h"
#include "../shape/Circle.h"
#include "../../board/Board.h"

namespace drawIt{

    class CircleTool: public Tool {
        private:
            std::shared_ptr<Circle> circle;
        public:
        void draw(Canvas& canvas){
            if(insideCanvas(canvas)) {
                if(Mouse::leftClicked()) {
                    Point mousePosition = Mouse::getPosition();
                    if(circle == nullptr) {
                        mousePosition.setY(mousePosition.getY());
                        std::cout<<mousePosition.getY()<<std::endl;
                        circle = std::make_shared<Circle>(
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