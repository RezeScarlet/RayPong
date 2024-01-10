#include <raylib.h>

class Player {
public:
    Rectangle rect;
    int speed;
    Vector2 center;
    int score;
    // TODO Make size variable based on screen size

    // Constructor
    Player(int number);

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
void Player::Move(KeyboardKey upKey, KeyboardKey downKey) {
    if (!(rect.y <= 0)) {
        if (IsKeyDown(upKey)) rect.y -= speed;

    }

    if (!(rect.y >= GetScreenHeight() - rect.height)) {
        if (IsKeyDown(downKey)) rect.y += speed;

    }
    center.y = rect.y+rect.height/2;

}

// Constructor
Player::Player(int number){
    // There are only 2 possible players
    switch (number) {
    case 1:
        this -> rect = {15, (float)GetScreenHeight()/2-50, 15, 100};
        this -> center = {rect.x + rect.width, rect.y + rect.height/2};
        break;
    case 2:
        this -> rect = {(float)GetScreenWidth()-30, (float)GetScreenHeight()/2-50, 15, 100};
        this -> center = {rect.x, rect.y + rect.height/2};

    default:
        break;
    }
    this -> speed = 10;
}

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
