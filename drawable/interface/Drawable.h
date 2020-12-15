#pragma once

class Drawable {
    protected:
        bool visible = true;
    public:
    virtual ~Drawable() {};
    virtual void display() = 0;

    virtual void setVisible(bool visible) { this->visible = visible; }
    virtual bool getVisible() { return this->visible; }
    virtual void hide() { this->visible = false; }
    virtual void show() { this->visible = true; }

};