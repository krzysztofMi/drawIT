#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(const int screenHeight): fileMenu{FileMenu{screenHeight}}{
    buttons.push_back(Button{Point{0, screenHeight-20}, 20, 20, "File", std::bind(&MainMenu::openFileMenu, this)});
    buttons.push_back(Button{Point{20, screenHeight-20}, 20, 20, "Toolbar", nullptr});
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
