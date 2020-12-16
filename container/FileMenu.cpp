#include "FileMenu.h"

FileMenu::FileMenu(const int screenHeight) {
    buttons.push_back(Button{Point{0, screenHeight-40}, 20, 20, "New", nullptr});
    buttons.push_back(Button{Point{0, screenHeight-60}, 20, 20, "Open", nullptr});
    buttons.push_back(Button{Point{0, screenHeight-80}, 20, 20, "Save", nullptr});
    buttons.push_back(Button{Point{0, screenHeight-100}, 20, 20, "Exit", nullptr});
    visible = false;
}