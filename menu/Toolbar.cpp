#include "Toolbar.h"
#include "../util/Color.h"
#include "../board/Board.h"
namespace drawIt{

Color Toolbar::color = Color{0.0, 1.0, 0.0};

Toolbar::Toolbar() {
    const int items = 5;
    int x = 0;
    int y = Board::screenHeight;
    buttons.push_back(Button{Point{x, y-60}, 20, 20, "P", 
            [this]()->void{this->mode = Mode::PENCIL; this->change = true;}});
    buttons.push_back(Button{Point{x+20, y-60}, 20, 20, "R", 
            [this]()->void{this->mode = Mode::RECTANGLE; this->change = true;}});
    buttons.push_back(Button{Point{x, y-40}, 20, 20, "T", 
            [this]()->void{this->mode = Mode::TRAIANGLE; this->change = true;}});
    buttons.push_back(Button{Point{x+20, y-40}, 20, 20, "C",
            [this]()->void{this->mode = Mode::CIRCLE; this->change = true;}});
    buttons.push_back(Button{Point{x, y-20}, 20, 20, "F", 
            [this]()->void{this->fill = fill ? false : true; this->change = true;}});
    visible = true;
}

}