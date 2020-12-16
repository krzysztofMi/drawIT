#include "Canvas.h"

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