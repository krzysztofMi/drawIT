#include <GL/freeglut.h>
#include <vector>
#include <memory> 
#include "container/MainMenu.h"
#include "container/interface/ButtonContainer.h"
#include "container/FileMenu.h"
#include "input/Mouse.h"

std::vector<std::shared_ptr<ButtonContainer>> containers;

int screenWidth;
int screenHeight; 

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    for(auto container: containers) {
      container->display();
    }
    glPopMatrix();
    glutSwapBuffers();
}

void init(void) {
    screenWidth = glutGet(GLUT_WINDOW_WIDTH);
    screenHeight = glutGet(GLUT_WINDOW_HEIGHT);
    containers.push_back(std::make_shared<MainMenu>(screenHeight));
    gluOrtho2D(0, screenWidth, 0, screenHeight);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void idle(void) {
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Drawrel");
    glutDisplayFunc(display);
    glutMouseFunc(Mouse::click);
    glutPassiveMotionFunc(Mouse::move);
    glutIdleFunc(idle);
    init();
    glutMainLoop();
    return 0; 
}
