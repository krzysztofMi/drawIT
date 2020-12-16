#pragma once

#include "Menu.h"
#include "../util/Color.h"
#include "../enum/Mode.h"

class Toolbar : public Menu{
    private:
        Mode mode;
        bool fill = false;
    public: 
        static Color color;
        Toolbar();

        Mode getMode() { return this->mode; }
};