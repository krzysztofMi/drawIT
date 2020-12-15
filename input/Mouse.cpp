#include "Mouse.h"
#include <iostream>

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

void Mouse::log() {
     std::cout<<button<<" "<<state<<std::endl;
}