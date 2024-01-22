#include "Screen.hpp"

class Player { private:
    Screen screen;
public:
    Rectangle rect;
    int speed;
    Vector2 center;
    int score = 0;
    float size;
    // TODO Make size variable based on screen size

    // Constructor
    Player(int number);
    Player();

    // Player Movement
    void Move(KeyboardKey upKey, KeyboardKey downKey);

    // Setter Getters
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

    int getHeight();
    int getWidth();
    // TODO height width setters
    

};

// Player input and collision 
inline void Player::Move(KeyboardKey upKey, KeyboardKey downKey) {
    if (!(rect.y <= 0)) {
        if (IsKeyDown(upKey)) rect.y -= speed;

    }

    if (!(rect.y >= screen.h - rect.height)) {
        if (IsKeyDown(downKey)) rect.y += speed;

    }
    center.y = rect.y+rect.height/2;

}

// Constructor
inline Player::Player(int number){
    // There are only 2 possible players
    this -> size = screen.h/5;
    this -> speed = 10;
    this -> rect = {0, screen.h/2-size/2, screen.w/57, size};
    this -> center.y = rect.y + rect.height/2;

    switch (number) {
    case 1:
        rect.x = rect.width;
        center.x = rect.x + rect.width;

        break;
    case 2:
        rect.x = screen.w-rect.width*2;
        center.x = rect.x;

        break;
    }
}
inline Player::Player(){}

// X Y setter getters to remove the rect from position related stuff
inline int Player::getX() {
    return rect.x;
}
inline int Player::getY() {
    return rect.y;
}

inline void Player::setX(int x) {
    rect.x = x;
}
inline void Player::setY(int y) {
    rect.y = y;
}

inline int Player::getHeight() {
    return rect.height;
}

inline int Player::getWidth() {
    return rect.width;
}
