#pragma once

#include "Tool.h"
#include "../shape/Rectangle.h"
#include <memory> 
namespace drawIt{

class RectangleTool: public Tool {
    private:
        std::shared_ptr<Rectangle> rectangle = nullptr;
    public:
        void draw(Canvas& canvas) {
            if(insideCanvas(canvas)) {
                if(Mouse::leftClicked()) {
                    Point mousePosition = Mouse::getPosition();
                    if(rectangle == nullptr) {
                        rectangle = std::make_shared<Rectangle>(
                            Mouse::getPosition(), 0, 0);
                        canvas.draw(rectangle);
                    } else {
                        Point point = rectangle->getPoint();
                        canvas.removeLast();
                        rectangle->setHeigth(mousePosition.getY()-point.getY());
                        rectangle->setWidth(mousePosition.getX()-point.getX());
                        canvas.draw(rectangle);
                    }
                } else {
                    rectangle = nullptr;
                }
            }
        }
};
}