#include "Ball.hpp"
#include <raymath.h>
class PowerUp {
private:
    Screen screen;
    int width = (screen.w + screen.h) / 100;
    int height = ((float)sqrt(3) / 2) * width;

public:
    bool visible = true;

    // receives the triangle coordenate and create the three vector
    Vector2 position = {(float)GetScreenWidth() / 2 + width, (float)GetScreenHeight() / 2};
    Vector2 v1 = {position.x, position.y - height};
    Vector2 v2 = {position.x - width/2, position.y};
    Vector2 v3 = {position.x + width/2, position.y};

    void Collide(Ball ball);
    void Respawn();
};

void PowerUp::Collide (Ball ball) {
    if (CheckCollisionPointCircle(v1, ball.position, ball.radius) || CheckCollisionPointCircle(v2, ball.position, ball.radius) || CheckCollisionPointCircle(v3, ball.position, ball.radius)) {

    // Make itself invisible and turn off collision
    v1 = Vector2Zero();
    v2 = Vector2Zero();
    v3 = Vector2Zero();
    visible = false;
    // Start powerup effect
    }

    // Start timer to spawn again
}

void Respawn() {
    // Set position and vectors
    visible = true;
    // Turn on collision
}