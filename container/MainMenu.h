#pragma once

#include <memory> 
#include "interface/Menu.h"
#include "FileMenu.h"

class MainMenu: public Menu {
    private:
        FileMenu fileMenu;
    public:
        MainMenu(const int screenHeight);
        void display() override;

        void openFileMenu();
};

