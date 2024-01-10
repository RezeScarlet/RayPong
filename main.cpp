// * Developed by
// * Yago Miguel Nunes (Notherman)
// :3 Clarisse Rosseti (RezeScarlet)

/*
- Criar um menu com opções de pontuação para partidas
- Power ups
    - Aumentar retangulo
    - Mudar a cor do fundo do jogo (epilepsicia)
    - Mudar tamanho da bola
    - Os pontos ganham hitbox e perdem pontos se acertados
    - Barrinha de duração
// - Testar o wrapper de c++
// - Player class and methods
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
#include <Ball.hpp>

using namespace std;

int main()
{

    // Anti aliasing
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(854, 480, "RayPong");
    SetTargetFPS(60);

    Ball ball;


    Player player1(1);
    Player player2(2);

    int frame = 0;
    int seg = 0;

    while (WindowShouldClose() == false)
    {

        // Timer 1 second
        // TODO create a nice looking method for this (YAGo esta no esquema já (eu acho))
        frame++;
        if (frame >= 60)
        {
            seg++;
            frame = 0;
            ball.Accelerate(0.1);
        }

        ball.Collide(player1, player2);

        ball.Move();

        // Player collision and Input
        player1.Move(KeyboardKey(KEY_W), KeyboardKey(KEY_S));
        player2.Move(KeyboardKey(KEY_UP), KeyboardKey(KEY_DOWN));

        // Shape drawing
        BeginDrawing();

        ClearBackground(PINK);

        DrawRectangleRec(player1.rect, WHITE);
        DrawRectangleRec(player2.rect, WHITE);

        DrawText(TextFormat("%d", player1.score), GetScreenWidth() / 4, 40, 40, WHITE);
        DrawText(TextFormat("%d", player2.score), GetScreenWidth() * 3 / 4, 40, 40, WHITE);

        DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);

        DrawCircle(ball.GetX(), ball.GetY(), ball.radius, WHITE);

        // Debug stuff
        DrawCircleV(player1.center, 3, RED);
        DrawCircleV(player2.center, 3, RED);
        DrawLine(0, GetScreenHeight() / 2, GetScreenWidth(), GetScreenHeight() / 2, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}