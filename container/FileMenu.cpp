#include "FileMenu.h"

FileMenu::FileMenu(const int screenHeight) {
    buttons.push_back(Button{Point{0, screenHeight-40}, 20, 20, "New"});
    buttons.push_back(Button{Point{0, screenHeight-60}, 20, 20, "Open"});
    buttons.push_back(Button{Point{0, screenHeight-80}, 20, 20, "Save"});
    buttons.push_back(Button{Point{0, screenHeight-100}, 20, 20, "Exit"});
    visible = false;
}