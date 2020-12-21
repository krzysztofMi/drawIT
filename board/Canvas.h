#pragma once

#include <vector>
#include <memory>
#include "../drawable/shape/Rectangle.h"

namespace drawIt{

class Canvas : public Rectangle {
    private:
        std::vector<std::shared_ptr<Shape>> drawable;
    public:
        Canvas(const Point point, const int dimX, const int dimY);
        void draw(std::shared_ptr<Shape> item);
        std::shared_ptr<Shape> getLastDraw();
        void resize();
        void removeLast();
        void clean();
        std::vector<std::shared_ptr<Shape>> getDrawable() { return drawable; }
        void setDrawable(std::vector<std::shared_ptr<Shape>> drawable) {this->drawable = drawable; }
        void display() override;
};

}