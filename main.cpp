#include <GL/freeglut.h>
#include <vector>
#include <memory> 
#include "input/Mouse.h"
#include "board/Board.h"

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    Board::getInstance().display();
    Mouse::displayPointer();
    glPopMatrix();
    glutSwapBuffers();
}

void init(void) {
    int screenWidth = glutGet(GLUT_WINDOW_WIDTH);
    int screenHeight = glutGet(GLUT_WINDOW_HEIGHT);
    Board::getInstance(screenHeight, screenWidth);
    gluOrtho2D(0, screenWidth, 0, screenHeight);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
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
