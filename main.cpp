/* 
- Criar um menu com opções de pontuação para partidas
- Power ups
    - Aumentar retangulo
    - Mudar a cor do fundo do jogo
    - Mudar tamanho da bola
    - O

    while (WindowShouldClose() == false){

        // Timer 1 seconds pontos ganham hitbox e perdem pontos se acertados
    - Barrinha de duração
- sistema de angulo para colisão
- reworkar para o wrapper de C++
*/
#include <iostream>
#include <raylib.h>
#include "include/raylib-cpp.hpp"

using namespace std;

int main () {

    raylib::Window window(854, 480, "RayPong");
    SetTargetFPS(60);
    // Anti aliasing
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    raylib::Vector2 ball(100, 100);
    int ballRadius = 15;
    // TODO Rework ballSpeed and its incrementation
    raylib::Vector2 ballSpeed(5, 5);

  //  Rectangle player1 = {15, GetScreenHeight()/2-100, 15, 100};
    raylib::Rectangle player1(15, GetScreenHeight()/2-50, 15, 100);
    int player1Score = 0;
    raylib::Rectangle player2(GetScreenWidth()-30, GetScreenHeight()/2-100, 15, 100);
    int player2Score = 0;

    int playerSpeed = 10;

    int frame = 0;
    int seg = 0;

    float speedEffect = 0.1;

        frame++;
        if(frame >= 60){
            seg++;
            frame = 0;
            if (ballSpeed.x > 0) ballSpeed.x += speedEffect;
            if (ballSpeed.y > 0) ballSpeed.y += speedEffect;
            if (ballSpeed.x < 0) ballSpeed.x -= speedEffect;
            if (ballSpeed.y < 0) ballSpeed.y -= speedEffect;
        }

        // Ball moviment
        ball.x += ballSpeed.x;
        ball.y += ballSpeed.y;

        // Ball collision
        // TODO turn this into a function
        // TODO Randomize respawn angle
        if (ball.x + ballRadius >= GetScreenWidth()) {
            ballSpeed.x *= -1;
            player1Score++;
            ballSpeed.x = 5;
            ballSpeed.y = 5;
            ball.x = GetScreenWidth()/4;
            ball.y = GetScreenHeight()/2;
        }

        if (ball.x - ballRadius <= 0) {
            ballSpeed.x *= -1;
            player2Score++;
            ballSpeed.x = -5;
            ballSpeed.y = -5;
            ball.x = GetScreenWidth()/4*3;
            ball.y = GetScreenHeight()/2;
        }

        if (ball.y + ballRadius >= GetScreenHeight()  || ball.y - ballRadius <= 0) {
            ballSpeed.y *= -1;
        }

        if (player1.CheckCollision(ball, ballRadius) || player2.CheckCollision(ball, ballRadius, player2)) {
            ballSpeed.x *= -1;

        }

        // Player collision
        // TODO turn this into a function
        if (!(player1.y <= 0)) {
            if (IsKeyDown(KEY_W)) player1.y -= playerSpeed;

        }

        if (!(player1.y >= GetScreenHeight() - player1.height)) {
            if (IsKeyDown(KEY_S)) player1.y += playerSpeed;

        }

        if (!(player2.y <= 0)) {
            if (IsKeyDown(KEY_UP)) player2.y -= playerSpeed;

        }

        if (!(player2.y >= GetScreenHeight() - player2.height)) {
            if (IsKeyDown(KEY_DOWN)) player2.y += playerSpeed;
        
        }

        // Shape drawing
        BeginDrawing();
        window.ClearBackground(BLACK);
        player1.Draw(WHITE);
        player2.Draw(WHITE);
        ball.DrawCircle(ballRadius, WHITE);
        DrawText(TextFormat("%d", player1Score), GetScreenWidth()/4, 40, 40, WHITE);
        DrawText(TextFormat("%d", player2Score), GetScreenWidth()*3/4, 40, 40, WHITE);
        DrawLine(GetScreenWidth()/2, 0, GetScreenWidth()/2, GetScreenHeight(), WHITE);
        EndDrawing();
    }

    window.Close();
    return 0;
}