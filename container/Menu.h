#pragma once

#include <vector>
#include "../drawable/Button.h"
#include "interface/Container.h"

class Menu: public Container {
    private:
        std::vector<Button> buttons;
    public: 
        Menu(const int screenHeight);
        void display();
};