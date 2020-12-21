#pragma once

#include <vector>
#include <memory>
#include "../drawable/Drawable.h"
#include "../menu/MainMenu.h"
#include "../menu/Toolbar.h"
#include "Canvas.h"
#include "../drawable/tool/Tool.h"

namespace drawIt{

class Board {
    private: 
       int windowWidth, windowHeight;
       std::vector<std::shared_ptr<Drawable>> drawable;
       MainMenu menu;
       Toolbar toolbar;
       std::shared_ptr<Tool> tool;
       Canvas canvas;
       Board(Board&);
       void operator=(const Board&);
       void switchTool();
    protected:
        Board();
    public:
        static int screenHeight;
        static int screenWidth;
        static bool resized; 

        static Board& getInstance(const int windowWidth, const int windowHeight);
        static Board& getInstance();

        static void setWindowSize();
        static void setWindowSize(int x, int y);
        void display();
        void clear(); 
        void switchToolbar();
        std::vector<std::shared_ptr<Shape>> getDrawable() {return canvas.getDrawable();}
        void loadShapes(std::vector<std::shared_ptr<Shape>> drawable) {canvas.setDrawable(drawable); }
};

}