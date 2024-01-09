/* 
- Criar um menu com opções de pontuação para partidas
- Power ups
    - Aumentar retangulo
    - Mudar a cor do fundo do jogo
    - Mudar tamanho da bola
    - Os pontos ganham hitbox e perdem pontos se acertados
    - Barrinha de duração
- sistema de angulo para colisão
- reworkar para o wrapper de C++
*/
#include <iostream>
#include <raylib.h>

using namespace std;

int main () {

    const int screenWidth = 854;
    const int screenHeight = 480;

    Vector2 ball = {100, 100};
    int ballRadius = 15;
    // TODO Rework ballSpeed and its incrementation
    Vector2 ballSpeed = {5, 5};

    Rectangle player1 = {15, screenHeight/2-100, 15, 100};
    int player1Score = 0;
    Rectangle player2 = {screenWidth-30, screenHeight/2-100, 15, 100};
    int player2Score = 0;

    int playerSpeed = 10;

    int frame = 0;
    int seg = 0;

    float speedEffect = 0.1;

    InitWindow(screenWidth, screenHeight, "Raypong");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){

        // Timer 1 second
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
        if (ball.x + ballRadius >= screenWidth) {
            ballSpeed.x *= -1;
            player1Score++;
            ballSpeed.x = 5;
            ballSpeed.y = 5;
            ball.x = screenWidth/4;
            ball.y = screenHeight/2;
        }

        if (ball.x - ballRadius <= 0) {
            ballSpeed.x *= -1;
            player2Score++;
            ballSpeed.x = -5;
            ballSpeed.y = -5;
            ball.x = screenWidth/4*3;
            ball.y = screenHeight/2;
        }

        if (ball.y + ballRadius >= screenHeight  || ball.y - ballRadius <= 0) {
            ballSpeed.y *= -1;
        }

        if (CheckCollisionCircleRec(ball, ballRadius, player1) || CheckCollisionCircleRec(ball, ballRadius, player2)) {
            ballSpeed.x *= -1;

        }

        // Player collision
        // TODO turn this into a function
        if (!(player1.y <= 0)) {
            if (IsKeyDown(KEY_W)) player1.y -= playerSpeed;

        }

        if (!(player1.y >= screenHeight - player1.height)) {
            if (IsKeyDown(KEY_S)) player1.y += playerSpeed;

        }

        if (!(player2.y <= 0)) {
            if (IsKeyDown(KEY_UP)) player2.y -= playerSpeed;

        }

        if (!(player2.y >= screenHeight - player2.height)) {
            if (IsKeyDown(KEY_DOWN)) player2.y += playerSpeed;
        
        }

        // Shape drawing
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangleRec(player1, WHITE);
        DrawRectangleRec(player2, WHITE);
        DrawText(TextFormat("%d", player1Score), screenWidth/4, 40, 40, WHITE);
        DrawText(TextFormat("%d", player2Score), screenWidth*3/4, 40, 40, WHITE);
        DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);
        DrawCircle(ball.x,ball.y,ballRadius, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}