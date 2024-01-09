/* 
- Criar um menu com opções de pontuação para partidas
- Power ups
    - Aumentar retangulo
    - Mudar a cor do fundo do jogo
    - Mudar tamanho da bola
    - Os pontos ganham hitbox e perdem pontos se acertados
    - Barrinha de duração
- Menu de configurações
    - adaptar jogo para resoluções maiores
    - Configuração de resolução e janela
- FPS adaptativo
    - configurar delta time
- sistema de angulo para colisão
*/
#include <iostream>
#include <raylib.h>
#include <Player.hpp>

using namespace std;

int main () {

    InitWindow(854, 480, "RayPong");

    Vector2 ball = {100, 100};
    int ballRadius = 15;
    // TODO Rework ballSpeed and its incrementation
    Vector2 ballSpeed = {5, 5};

    // TODO Transform into a Player class

    Player Player1Obj(1);
    Rectangle player1 = {15, GetScreenHeight()/2-50, 15, 100};
    Vector2 centerPlayer1 = {player1.x + player1.width, player1.y + player1.height/2};
    int player1Score = 0;
    Rectangle player2 = {GetScreenWidth()-30, GetScreenHeight()/2-50, 15, 100};
    int player2Score = 0;

    int playerSpeed = 10;

    int frame = 0;
    int seg = 0;

    float speedEffect = 0.1;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        centerPlayer1.x = player1.x + player1.width;
        centerPlayer1.y = player1.y + player1.height/2;

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

        if (CheckCollisionCircleRec(ball, ballRadius, player1) || CheckCollisionCircleRec(ball, ballRadius, player2)) {
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
        ClearBackground(BLACK);
        //DrawRectangleRec(player1, WHITE);
        DrawRectangleRec(Player1Obj.rectangle, WHITE);
        DrawRectangleRec(player2, WHITE);
        DrawText(TextFormat("%d", player1Score), GetScreenWidth()/4, 40, 40, WHITE);
        DrawText(TextFormat("%d", player2Score), GetScreenWidth()*3/4, 40, 40, WHITE);
        DrawLine(GetScreenWidth()/2, 0, GetScreenWidth()/2, GetScreenHeight(), WHITE);
        DrawCircle(ball.x,ball.y,ballRadius, WHITE);

        // Degug stuff
        DrawCircle(player1.x+player1.width, player1.y+player1.height/2, 3, RED);
        DrawLine(0, GetScreenHeight()/2, GetScreenWidth(), GetScreenHeight()/2, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// void adjustRectangle(int shape, Rectangle player){
//     switch(shape) {
//     case 0:
//         //? NORMAL SHAPE
//         // code block
//         break;
//     case 1:
//         //? LARGER SHAPE
//         // code block
//         break;
//     case -1:
//         //? SHORT SHAPE
//         // code block
//         break;
//     default:
//         // code block
//     }}