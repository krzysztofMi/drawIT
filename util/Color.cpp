#include "Color.h"
namespace drawIt{

Color::Color(const float r, const float g, const float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}
void Color::setColor(const float r, const float g, const float b){
    this->r = r;
    this->g = g;
    this->b = b;
}

}