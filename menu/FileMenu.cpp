#include "FileMenu.h"
#include "../board/Board.h"

FileMenu::FileMenu(const int screenHeight) {
    buttons.push_back(Button{Point{0, screenHeight-40}, 20, 20, "New", std::bind(&FileMenu::newFile, this)});
    buttons.push_back(Button{Point{0, screenHeight-60}, 20, 20, "Open", std::bind(&FileMenu::open, this)});
    buttons.push_back(Button{Point{0, screenHeight-80}, 20, 20, "Save", std::bind(&FileMenu::save, this)});
    buttons.push_back(Button{Point{0, screenHeight-100}, 20, 20, "Exit", std::bind(&FileMenu::exit, this)});
    visible = false;
}

void FileMenu::newFile() {
    Board::getInstance().clear();
}

void FileMenu::open() {
//TODO
}

void FileMenu::save() {
//TODO
}

void FileMenu::exit() {
    glutLeaveMainLoop();
}