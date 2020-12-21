#pragma once

#include "Tool.h"
#include "../shape/Line.h"
#include <iostream>

namespace drawIt {

class LineTool: public Tool {
    protected:
        std::shared_ptr<Line> line;
    public:
    void draw(Canvas& canvas){
         if(insideCanvas(canvas)) {
                if(Mouse::leftClicked()) {
                    Point mousePosition = Mouse::getPosition();
                    if(line == nullptr) {
                        line = std::make_shared<Line>(
                            mousePosition, mousePosition);
                        canvas.draw(line);
                    } else {
                        canvas.removeLast();
                        line->setY(mousePosition);
                        canvas.draw(line);
                    }
                } else {
                    line = nullptr;
                }    
        }
    }
};

}