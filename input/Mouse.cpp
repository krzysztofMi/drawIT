#include "Mouse.h"
#include <iostream>
#include <GL/freeglut.h>

Point Mouse::position = Point{0, 0};
int Mouse::button = -10;
int Mouse::state = -10;
bool Mouse::released = false;

void Mouse::move(const int posX, const int posY) {
    Mouse::position.setX(posX);
    Mouse::position.setY(posY);
}

void Mouse::click(const int button, const int state, const int posX, const int posY) {
    Mouse::button = button;
    if(Mouse::state != state) {
        Mouse::released = true;
    } else {
        Mouse::released = false;
    }
    Mouse::state = state;
    Mouse::position.setX(posX);
    Mouse::position.setY(posY);
}

bool Mouse::clicked() {
    if(state == 0) {
        return true;
    }
    return false;
}

bool Mouse::leftClicked() {
    if(state == 0 && button == 0) {
        return true;
    }
    return false;
    return false;
}

bool Mouse::middleClicked() {
    if(state == 0 && button == 1) {
        return true;
    }
    return false;
}

bool Mouse::rightClicked() {
    if(state == 0 && button == 2) {
        return true;
    }
    return false;
}

bool Mouse::isReleased() {
    return released;
}

void Mouse::log(const std::string& info) {
    std::cout<<info<<std::endl;
    std::cout<<"Position: "<<position.getX()<<" "<<position.getY()<<std::endl;
    std::cout<<button<<" "<<state<<std::endl;
}

void Mouse::drawPointer() {
	glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
	glEnd();
	glBegin(GL_LINE_LOOP);
        glVertex2f(0.0f, 1.0f);
        glVertex2f(0.0f, -1.0f);
	glEnd();
}

void Mouse::displayPointer() {
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(2.0f);
	glPushMatrix();
	glTranslatef(position.getX(), glutGet(GLUT_WINDOW_HEIGHT) - position.getY(), 1.0f);
	glScalef(5.0f, 5.0f, 1.0f);
	drawPointer();
	glPopMatrix();
}