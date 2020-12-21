#pragma once

#include "Menu.h"
#include "../util/Color.h"
#include "../enum/Mode.h"
namespace drawIt{

class Toolbar : public Menu{
    private:
        Mode mode;
        bool change = false;
    public: 
        static Color color;
        static Color borderColor;
        static bool fill;
        Toolbar();
        bool getChange() {return change; }
        void setChange(bool change) {this->change = change;}
        Mode getMode() { return this->mode; }
};

}