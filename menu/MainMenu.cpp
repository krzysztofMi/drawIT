#include "MainMenu.h"
#include <iostream>
#include "../board/Board.h"
namespace drawIt{

MainMenu::MainMenu(): fileMenu{FileMenu{}}{
    buttons.push_back(Button{Point{0, 0}, 53, 20, "File",
                 std::bind(&MainMenu::openFileMenu, this)});
    buttons.push_back(Button{Point{53, 0}, 80, 20, "Toolbar", 
                 []()->void{Board::getInstance().switchToolbar();}});
    visible = true;
};

void MainMenu::display() {
    for(auto button: buttons) {
        button.display();
    }
    fileMenu.display();
}

void MainMenu::openFileMenu() {
    fileMenu.show();
}

}