#include "FileMenu.h"
#include "../board/Board.h"
#include "../file/FileMenager.h"
namespace drawIt{

FileMenu::FileMenu() {
    buttons.push_back(Button{Point{0, 20}, 53, 20, "New", std::bind(&FileMenu::newFile, this)});
    buttons.push_back(Button{Point{0, 40}, 53, 20, "Open", std::bind(&FileMenu::open, this)});
    buttons.push_back(Button{Point{0, 60}, 53, 20, "Save", std::bind(&FileMenu::save, this)});
    buttons.push_back(Button{Point{0, 80}, 53, 20, "Exit", std::bind(&FileMenu::exit, this)});
    visible = false;
}

void FileMenu::newFile() {
    Board::getInstance().clear();
}

void FileMenu::open() {
    FileMenager menager{"save.txt"};
    Board::getInstance().clear();
    Board::getInstance().loadShapes( menager.retriveVector() );
}

void FileMenu::save() {
    FileMenager menager{"save.txt"};
    menager.saveVector(Board::getInstance().getDrawable());
}

void FileMenu::exit() {
    glutLeaveMainLoop();
}

}