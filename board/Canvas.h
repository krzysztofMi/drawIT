#pragma once

#include <vector>
#include <memory>
#include "../drawable/shape/Rectangle.h"

namespace drawIt{

class Canvas : public Rectangle {
    private:
        std::vector<std::shared_ptr<Drawable>> drawable;
    public:
        Canvas(const Point point, const int dimX, const int dimY);
        void draw(std::shared_ptr<Drawable> item);
        std::shared_ptr<Drawable> getLastDraw();
        void removeLast();
        void clean();
        void display() override;
};

}