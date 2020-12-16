GCC = g++
LIB = -lopengl32 -lfreeglut -lglu32
DOTHERS_P = drawable\others
DOTHERS = $(DOTHERS_P)\Button.cpp $(DOTHERS_P)\Text.cpp
DSHAPE_P = drawable\shape
DSHAPE = $(DSHAPE_P)\Rectangle.cpp
DTOOL_P = drawable\tool
DTOOL = $(DTOOL_P)\PENCIL.cpp
INPUT = input\Mouse.cpp
MENU = menu\FileMenu.cpp menu\MainMenu.cpp menu\Toolbar.cpp
UTIL = util\Color.cpp
BOARD = board\Board.cpp board\Canvas.cpp
OPTIONS = -g -o drawrel

all:
	$(GCC) $(OPTIONS) main.cpp $(DOTHERS) $(DSHAPE) $(DTOOL) $(INPUT) $(MENU) $(UTIL) $(BOARD) $(LIB)
