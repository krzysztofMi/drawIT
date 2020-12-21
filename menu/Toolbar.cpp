#include "Toolbar.h"
#include "../util/Color.h"
#include "../board/Board.h"
namespace drawIt{

Color Toolbar::color = Color{0.0, 1.0, 0.0};
bool Toolbar::fill = false;

Toolbar::Toolbar() {
    const int items = 5;
    int x = 0;
    int y = Board::screenHeight;
    buttons.push_back(Button{Point{x, y-60}, 20, 20, "P", 
            [this]()->void{this->mode = Mode::PENCIL; this->change = true;}});
    buttons.push_back(Button{Point{x+20, y-60}, 20, 20, "L", 
            [this]()->void{this->mode = Mode::LINE; this->change = true;}});
    buttons.push_back(Button{Point{x, y-40}, 20, 20, "R", 
            [this]()->void{this->mode = Mode::RECTANGLE; this->change = true;}});
    buttons.push_back(Button{Point{x+20, y-40}, 20, 20, "T", 
            [this]()->void{this->mode = Mode::TRAIANGLE; this->change = true;}});
    buttons.push_back(Button{Point{x, y-20}, 20, 20, "C",
            [this]()->void{this->mode = Mode::CIRCLE; this->change = true;}});
    buttons.push_back(Button{Point{x+20, y-20}, 20, 20, "F", 
            [this]()->void{ 
                    Toolbar::fill = Toolbar::fill? false : true;
                    this->change = true;
                    if(Toolbar::fill) {
                        buttons[5].setBackgroundColor(Color{0.2, 0.3, 0.4});  
                    }else {
                        buttons[5].setBackgroundColor(Color{0.5, 0.6, 0.7});
                    }
                    }});
    visible = true;
}

}