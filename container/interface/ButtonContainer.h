#pragma once

#include <vector>
#include "../../drawable/Button.h"

class ButtonContainer: public Drawable {
    protected:
        std::vector<Button> buttons;
    public:
        virtual ~ButtonContainer() {};
};