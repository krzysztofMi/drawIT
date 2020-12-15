#include "MainMenu.h"

MainMenu::MainMenu(const int screenHeight): fileMenu{FileMenu{screenHeight}}{
    buttons.push_back(Button{Point{0, screenHeight-20}, 20, 20, "File"});
    buttons.push_back(Button{Point{20, screenHeight-20}, 20, 20, "Toolbar"});
    visible = true;
};

void MainMenu::display() {
    for(auto button: buttons) {
        button.display();
    }
    fileMenu.display();
}
