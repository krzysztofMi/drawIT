#include <GL/freeglut.h>
#include <vector>
#include <memory> 
#include "input/Mouse.h"
#include "board/Board.h"
#include <iostream>
using namespace drawIt;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    Board::getInstance().display();
    Mouse::displayPointer();
    glPopMatrix();
    glutSwapBuffers();
}

void init(void) {
    Board::setWindowSize();
    Board::getInstance();
    gluOrtho2D(0, Board::screenWidth, 0, Board::screenHeight);
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
    glutCreateWindow("DrawIT");
    glutDisplayFunc(display);
    glutMouseFunc(Mouse::click);
    glutMotionFunc(Mouse::move);
    glutPassiveMotionFunc(Mouse::move);
    glutReshapeFunc(Board::setWindowSize);
    glutIdleFunc(idle);
    init();
    glutMainLoop();
    return 0; 
}
