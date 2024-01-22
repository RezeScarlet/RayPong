#include "Player.hpp"
#include <raymath.h>
#include <iostream>

class Ball {
private:
  Screen screen;

public:
  Vector2 position = {(float)screen.w / 2, (float)screen.h / 2};
  Player lastTouch;

  float speed = 8;
  Vector2 direction = {-5, -5};
  int radius = (screen.w + screen.h) / 100;

  Ball(Player lastTouch);

  void Move();

  void Accelerate(float acceleration);

  void Collide(Player &player1, Player &player2);
  void CollideWithPlayer(float reflectTo, Player &player);

  // Setter/Getters
  void SetX(int X);
  void SetY(int Y);
  int GetX();
  int GetY();
};

inline Ball::Ball(Player lastTouch) {
  this -> lastTouch = lastTouch;
}

inline void Ball::Move() {
  position = Vector2Add(position, Vector2Scale(Vector2Normalize(direction), speed));
}

inline void Ball::Accelerate(float acceleration) {
  speed += acceleration;  
}

// TODO Rework this function
inline void Ball::Collide(Player &player1, Player &player2) {
  if (position.x + radius >= screen.w) {
    player1.score++;
    direction = {5, (float)GetRandomValue(-5, 5)};
    position = {(float)screen.w / 4, (float)screen.h / 2};
  }

  if (position.x - radius <= 0) {
    player2.score++;
    direction = {-5, (float)GetRandomValue(-5, 5)};
    position = {(float)screen.w / 4 * 3, (float)screen.h / 2};
  }

  if (position.y + radius >= screen.h || position.y - radius <= 0) {
    direction.y *= -1;
  }
  
  CollideWithPlayer(1, player1);
  CollideWithPlayer(-1, player2);
}

inline void Ball::CollideWithPlayer(float reflectTo, Player &player) {
  if (CheckCollisionCircleRec(position, radius, player.rect)) {
    // Lerp between the two vector to make ball reflect in the correct angle
    // It does it by remaping the distance(can be negative) between the ball and center of the player to a value from 0 to 1  
    direction = Vector2Lerp({reflectTo, -1}, {reflectTo, 1}, Remap(position.y - player.getY() - player.getHeight()/2 , -player.getHeight()/2, player.getHeight()/2, 0, 1));
    
    // This calc is kinda wierd, so i'll be leaving these debug couts were
    // std::cout << "player height: " << player.getHeight() << '\n';
    // std::cout << "input: " << position.y - player.getY() - player.getHeight()/2 << "\nStart: " << -player.getHeight()/2 - radius << "\nEnd: " << player.getHeight()/2 + radius<< '\n';
    // std::cout << "Remap: " << Remap(position.y - player.getY() - player.getHeight()/2, -player.getHeight()/2, player.getHeight()/2, 0, 1) << '\n';
    lastTouch = player;
    direction = Vector2Multiply(Vector2Normalize(direction), {speed, speed});
  
  }
}

inline void Ball::SetX(int X) { position.x = X; }

inline void Ball::SetY(int Y) { position.y = Y; }

inline int Ball::GetX() { return position.x; }

inline int Ball::GetY() { return position.y; }
