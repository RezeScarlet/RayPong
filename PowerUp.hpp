#include "Ball.hpp"
#include <raymath.h>
class PowerUp {
private:
  Screen screen;
  float width = (screen.w + screen.h) / 50;
  float height = ((float)sqrt(3) / 2) * width;

public:
  bool visible = false;

  // receives the triangle coordenate and create the three vector
  Vector2 position = {(float)GetScreenWidth() / 2 + width,
                      (float)GetScreenHeight() / 2};
  Vector2 v1 = {position.x, position.y - height};
  Vector2 v2 = {position.x - width / 2, position.y};
  Vector2 v3 = {position.x + width / 2, position.y};

  void Collide(Ball ball);
  void Respawn();
};

inline void PowerUp::Collide(Ball ball) {
  if (CheckCollisionPointCircle(v1, ball.position, ball.radius) ||
      CheckCollisionPointCircle(v2, ball.position, ball.radius) ||
      CheckCollisionPointCircle(v3, ball.position, ball.radius)) {

    // Make itself invisible and turn off collision
    v1 = Vector2Zero();
    v2 = Vector2Zero();
    v3 = Vector2Zero();
    visible = false;

    // Start powerup effect
    // todo make duration bar
    /*
    PowerUps chance table
    - Player bigger
    - player smaller
    - color (correct player color)
        - normal color
        - rainbow
    - Ball bigger
    - ball smaller
    - ball speed
    - ball slower
    - Multi Balls
    */

    int effect = GetRandomValue(1, 100);
    if (effect < 100) {
      ball.lastTouch->setHeight(300);
    }
  }

  // Start timer to spawn again
}

inline void PowerUp::Respawn() {
  // Set position and vectors
  visible = true;
  position = {(float)GetRandomValue(screen.w / 6, screen.w / 6 * 5),
              (float)GetRandomValue(0 + height, screen.h)};
  v1 = {position.x, position.y - height};
  v2 = {position.x - width / 2, position.y};
  v3 = {position.x + width / 2, position.y};
  // Turn on collision
}
