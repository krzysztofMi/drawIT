#include "Toolbar.h"
#include "../util/Color.h"

Color Toolbar::color = Color{0.0, 1.0, 0.0};

Toolbar::Toolbar() {
    const int items = 5;
    int x = 0;
    int y = 20*items/2;
    buttons.push_back(Button{Point{x, y}, 20, 20, "P", 
            [this]()->void{this->mode = Mode::PENCIL;}});
    buttons.push_back(Button{Point{x+20, y}, 20, 20, "R", 
            [this]()->void{this->mode = Mode::RECTANGLE;}});
    buttons.push_back(Button{Point{x, y-20}, 20, 20, "T", 
            [this]()->void{this->mode = Mode::TRAIANGLE;}});
    buttons.push_back(Button{Point{x+20, y-20}, 20, 20, "C",
            [this]()->void{this->mode = Mode::CIRCLE;}});
    buttons.push_back(Button{Point{x, y-40}, 20, 20, "F", 
            [this]()->void{this->fill = fill ? false : true;}});
    visible = true;
}

