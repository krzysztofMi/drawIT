#include "Menu.h"

Menu::Menu(const int screenHeigth) {
    buttons.push_back(Button{Point{0, screenHeigth-20}, 20, 20, "Exit"});
    buttons.push_back(Button{Point{20, screenHeigth-20}, 20, 20, "Start"});
    buttons.push_back(Button{Point{40, screenHeigth-20}, 20, 20, "Stop"});
}

void Menu::display() {
    for(auto bttn: buttons) {
        bttn.display();
    }
}