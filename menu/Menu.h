#pragma once

#include <vector>
#include <vector>
#include "../drawable/Drawable.h"
#include "../drawable/others/Button.h"
namespace drawIt{

class Menu: public Drawable {
    protected:
        std::vector<Button> buttons;
    public:
        virtual ~Menu(){};
        void display() override {
            if(visible) {
                for(auto bttn: buttons) {
                    bttn.display();
                }
            }
        }
};

}