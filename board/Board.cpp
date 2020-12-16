#include "Board.h"
#include "../menu/MainMenu.h"
#include "../menu/Toolbar.h"
#include "../drawable/tool/Pencil.h"

Board::Board(const int screenHeight, const int screenWidth): 
        screenHeight{screenHeight}, screenWidth{screenWidth}, 
        canvas{Point{10, 10}, screenWidth, screenHeight}, menu{screenHeight}, toolbar{} {
    tool = std::make_shared<Pencil>();
}

Board& Board::getInstance(const int screenHeight, const int screenWidth) {
    static Board b(screenHeight, screenWidth);
    return b;
}
Board& Board::getInstance(){
    static Board b(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
    return b;
}

void Board::display() {
    canvas.display();
    switchTool();
    tool->draw(canvas);
    menu.display();
    toolbar.display();
}

void Board::clear() { drawable.clear(); }

void Board::switchTool() {
    switch(toolbar.getMode()) {
        case Mode::PENCIL:
             tool = std::make_shared<Pencil>();
        default:
            break;
    }
}