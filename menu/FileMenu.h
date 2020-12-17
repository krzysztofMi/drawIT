#pragma once

#include "Menu.h"
namespace drawIt{

class FileMenu: public Menu {
    
    public:
        FileMenu();
    private:
        void exit();
        void newFile();
        void open();
        void save();
};

}