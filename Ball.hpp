class Ball {

public:
    Vector2 position = {(float)GetScreenWidth()/2, (float)GetScreenHeight()/2};
    
    // When one of the coordenates is 0 the ball goes straight
    // So the bigger the X coordenate straigter it goes
    // if the ball hits the center of the player y speed should be 0 (straight foward)
    // ? if the ball hits the extreme end it should be?
    Vector2 direction = {-5, -5};
    int radius = 15;

    // Constructor
    Ball();

    void Move();

    void Accelerate(float acceleration);

    void Collide(Player player1, Player player2);

    // Setter/Getters
    void SetX(int X);
    void SetY(int Y);
    int GetX();
    int GetY();

};

// Constructor
// Change to singleton in the future if needed
Ball::Ball() {
}

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
    if (position.x + radius >= GetScreenWidth()) {
        direction.x *= -1;
        player1.score++;
        direction.x = 5;
        direction.x = 5;
        position.x = GetScreenWidth() / 4;
        position.y = GetScreenHeight() / 2;
    }

    if (position.x - radius <= 0) {
        direction.x *= -1;
        player2.score++;
        direction.x = -5;
        direction.x = -5;
        position.x = (float)GetScreenWidth() / 4 * 3;
        position.y = (float)GetScreenHeight() / 2;
    }

    if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0) {
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


