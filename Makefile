GCC = g++
LIB = -lopengl32 -lfreeglut -lglu32
DRAW = drawable
SOURCES = main.cpp $(DRAW)\Button.cpp util\Color.cpp $(DRAW)\Text.cpp container\Menu.cpp
OPTIONS = -g -o drawrel

all:
	$(GCC) $(OPTIONS) $(SOURCES) $(LIB)
