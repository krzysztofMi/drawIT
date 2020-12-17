#pragma once

#include <string>
#include "../util/Point.h"

namespace drawIt{

class Mouse {
    private: 
        static Point position;
        static int button;
        static int state;
        static bool released;
        static void drawPointer();
    public:
        static void move(const int posX, const int posY);
        static void click(const int button, const int state, const int posX, const int posY);
        static Point getPosition() {return Mouse::position;}
        static bool clicked();
        static bool leftClicked();
        static bool rightClicked();
        static bool middleClicked();
        static bool isReleased();

        static void displayPointer();
        static void log(const std::string&);
};

}