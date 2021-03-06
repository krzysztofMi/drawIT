#include "Canvas.h"
#include <iostream>
#include "Board.h"

namespace drawIt{

Canvas::Canvas(const Point point, const int dimX, const int dimY)
    : Rectangle(point, dimX, dimY, Color{1.0f, 1.0f, 1.0f}, true) {}

void Canvas::display() {
    displayFill();
    for(auto item : drawable) {
        item->display();
    }
    if(Board::resized) {
        this->setWidth(Board::screenWidth);
        this->setHeigth(Board::screenHeight);
        Board::resized = false;
    }
}

void Canvas::draw(std::shared_ptr<Shape> item) {
    drawable.push_back(item);
}

void Canvas::clean() {
    drawable.clear();
}

std::shared_ptr<Shape> Canvas::getLastDraw() {
    return drawable.back();
}

void Canvas::removeLast() {
    if(drawable.size() > 0) {
        drawable.pop_back();
    }
}

}