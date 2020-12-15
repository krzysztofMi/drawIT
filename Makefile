GCC = g++
LIB = -lopengl32 -lfreeglut -lglu32
DRAW = drawable
SOURCES = main.cpp $(DRAW)\Button.cpp util\Color.cpp $(DRAW)\Text.cpp container\MainMenu.cpp container\FileMenu.cpp input/Mouse.cpp $(DRAW)\Rectangle.cpp container\Toolbar.cpp
OPTIONS = -g -o drawrel

all:
	$(GCC) $(OPTIONS) $(SOURCES) $(LIB)
