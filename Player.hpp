#include <raylib.h>

class Player {
public:
    Rectangle rectangle;
    int speed;
    Vector2 center;
    

    Player(int number);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    
    ~Player();
};

// Constructor
Player::Player(int number){
    // There are only 2 possible players
    switch (number) {
    case 1:
        this -> rectangle = {15, (float)GetScreenHeight()/2-50, 15, 100};
        break;
    case 2:
        this -> rectangle = {(float)GetScreenWidth()-30, (float)GetScreenHeight()/2-50, 15, 100};
    default:
        break;
    }
    this -> speed = 10;
    this -> center = {rectangle.x + rectangle.width, rectangle.y + rectangle.height/2};
}

// X Y setter getters to remove the rectangle from the equation
inline void Player::setX(int x) {
    rectangle.x = x;
}

inline void Player::setY(int y) {
    rectangle.y = y;
}

inline int Player::getX() {
    return rectangle.x;
}

inline int Player::getY() {
    return rectangle.y;
}
Player::~Player(){
}
