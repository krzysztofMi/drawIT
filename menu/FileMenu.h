#pragma once

#include "Menu.h"

class FileMenu: public Menu {
    
    public:
        FileMenu(const int screenHeight);
    private:
        void exit();
        void newFile();
        void open();
        void save();
};