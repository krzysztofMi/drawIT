#include "Board.h"
#include <iostream>
#include <GL/freeglut.h>
#include "../menu/MainMenu.h"
#include "../menu/Toolbar.h"
#include "../drawable/tool/Pencil.h"
#include "../drawable/tool/RectangleTool.h"
#include "../drawable/tool/LineTool.h"
#include "../drawable/tool/TriangleTool.h"


namespace drawIt{

int Board::screenWidth = 0;
int Board::screenHeight = 0;

Board::Board() : 
        canvas{Point{10, 10}, Board::screenWidth, Board::screenHeight}, menu{}, toolbar{} {
    tool = std::make_shared<Pencil>();
}

Board& Board::getInstance(){
    setWindowSize();
    static Board b;
    return b;
}

void Board::display() {
    canvas.display();
    switchTool();
    tool->draw(canvas);
    menu.display();
    toolbar.display();
}

void Board::clear() { canvas.clean(); }

void Board::switchTool() {
    if(toolbar.getChange()) {
        toolbar.setChange(false);
        switch(toolbar.getMode()) {
            case Mode::PENCIL:
                tool = std::make_shared<Pencil>();
                break;
            case Mode::LINE:
                tool = std::make_shared<LineTool>();
                break;
            case Mode::RECTANGLE:
                tool = std::make_shared<RectangleTool>();
                break;
            case Mode::TRAIANGLE:
                tool = std::make_shared<TriangleTool>();
                break;
            default:
                break;
        }
    }
}

void Board::setWindowSize() {
    screenWidth = glutGet(GLUT_WINDOW_WIDTH);
    screenHeight = glutGet(GLUT_WINDOW_HEIGHT);
}

void Board::setWindowSize(int x, int y) {
    screenWidth = x;
    screenHeight = y;
    glViewport(0, 0, x, y); // reset the viewport
    glMatrixMode(GL_PROJECTION); // modify the projection matrix
    glLoadIdentity();            // load an identity matrix into the projection matrix
    glOrtho(0, x, 0, y, -1.0, 1.0); // create new projection matrix
    glMatrixMode(GL_MODELVIEW); // return to the model matrix
    glLoadIdentity();  
}

void Board::switchToolbar() {
        if(toolbar.getVisible()) {
            toolbar.hide();
        }else {
            toolbar.show();
        }
}

}