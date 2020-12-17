#include "Canvas.h"
#include <iostream>
namespace drawIt{

Canvas::Canvas(const Point point, const int dimX, const int dimY)
    : Rectangle(point, dimX, dimY) {}

void Canvas::display() {
    displayRectangle(Color{1.0, 1.0, 1.0});
    for(auto item : drawable) {
        item->display();
    }
}

void Canvas::draw(std::shared_ptr<Drawable> item) {
    drawable.push_back(item);
}

void Canvas::clean() {
    drawable.clear();
}

std::shared_ptr<Drawable> Canvas::getLastDraw() {
    return drawable.back();
}

void Canvas::removeLast() {
    if(drawable.size() > 0) {
        drawable.pop_back();
    }
}

}