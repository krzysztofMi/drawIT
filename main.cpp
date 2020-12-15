#include <GL/freeglut.h>
#include "container/Menu.h"
#include <vector>
#include <memory> 

std::vector<std::shared_ptr<Container>> containers;

int screenWidth;
int screenHeight; 

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    for(auto container: containers) {
      container->display();
    }
    glutSwapBuffers();
}

void init(void) {
    screenWidth = glutGet(GLUT_WINDOW_WIDTH);
    screenHeight = glutGet(GLUT_WINDOW_HEIGHT);
    containers.push_back(std::make_shared<Menu>(screenHeight));
    gluOrtho2D(0, screenWidth, 0, screenHeight);
    glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Drawrel");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0; 
}
