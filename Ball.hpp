class Ball {
private:
    Screen screen;

public:
    Vector2 position = {(float)screen.w/2, (float)screen.h/2};
    
    // When one of the coordenates is 0 the ball goes straight
    // So the bigger the X coordenate straigter it goes
    // if the ball hits the center of the player y speed should be 0 (straight foward)
    // ? if the ball hits the extreme end it should be?
    Vector2 direction = {-5, -5};
    int radius = (screen.w + screen.h) / 100 ;

    void Move();

    void Accelerate(float acceleration);

    void Collide(Player player1, Player player2);

    // Setter/Getters
    void SetX(int X);
    void SetY(int Y);
    int GetX();
    int GetY();

};

inline void Ball::Move() {
    position.x += direction.x;
    position.y += direction.y;
}

inline void Ball::Accelerate(float acceleration) {
    if (direction.x > 0)
        direction.x += acceleration;
    if (direction.y > 0)
        direction.y += acceleration;
    if (direction.x < 0)
        direction.x -= acceleration;
    if (direction.y < 0)
        direction.y -= acceleration;
}

inline void Ball::Collide(Player player1, Player player2) {
    if (position.x + radius >= screen.w) {
        direction.x *= -1;
        player1.score++;
        direction.x = 5;
        direction.x = 5;
        position.x = screen.w / 4;
        position.y = screen.h / 2;
    }

    if (position.x - radius <= 0) {
        direction.x *= -1;
        player2.score++;
        direction.x = -5;
        direction.x = -5;
        position.x = (float)screen.w / 4 * 3;
        position.y = (float)screen.h / 2;
    }

    if (position.y + radius >= screen.h || position.y - radius <= 0) {
        direction.y *= -1;
    }

    if (CheckCollisionCircleRec(position, radius, player1.rect) || CheckCollisionCircleRec(position, radius, player2.rect)) {
        direction.x *= -1;
    }
}

inline void Ball::SetX(int X) {
    position.x = X;
}

inline void Ball::SetY(int Y) {
    position.y = Y;
}

inline int Ball::GetX() {
    return position.x;
}

inline int Ball::GetY() {
    return position.y;
}


