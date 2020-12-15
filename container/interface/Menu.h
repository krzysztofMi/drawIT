#pragma once

#include <vector>
#include "../../drawable/Button.h"
#include "ButtonContainer.h"

class Menu: public ButtonContainer {
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