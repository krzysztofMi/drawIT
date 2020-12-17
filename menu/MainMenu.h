#pragma once

#include <memory> 
#include "Menu.h"
#include "FileMenu.h"
namespace drawIt{

class MainMenu: public Menu {
    private:
        FileMenu fileMenu;
    public:
        MainMenu();
        void display() override;

        void openFileMenu();
};

}