#pragma once

#include <vector>
#include <memory>
#include "../drawable/Drawable.h"
#include "../menu/MainMenu.h"
#include "../menu/Toolbar.h"
#include "Canvas.h"
#include "../drawable/tool/Tool.h"

class Board {
    private: 
       int screenHeight, screenWidth;
       std::vector<std::shared_ptr<Drawable>> drawable;
       MainMenu menu;
       Toolbar toolbar;
       std::shared_ptr<Tool> tool;
       Canvas canvas;
       Board(Board&);
       void operator=(const Board&);
       void switchTool();
    protected:
        Board(const int screenHeight, const int screenWidth);
    public:
        static Board& getInstance(const int screenHeight, const int screenWidth);
        static Board& getInstance();

        void display();
        void clear(); 
};