#include "Pencil.h"
#include "../shape/DrawablePoint.h"
#include <iostream>
namespace drawIt{

void Pencil::draw(Canvas& canvas) {
    if(insideCanvas(canvas)) {
        if(Mouse::leftClicked()) {
            canvas.draw(std::make_shared<DrawablePoint>(Mouse::getPosition()));
        }
    }
}

}