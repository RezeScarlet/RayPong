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
#include "PowerUp.hpp"
#include "Timer.hpp"


using namespace std;

int main() {

    // Anti aliasing
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(854, 480, "RayPong");
    SetTargetFPS(60);

    Screen screen;
    Timer timer;
    Player player1(1);
    Player player2(2);

    Ball ball(player1);

    PowerUp powerUp;

    while (WindowShouldClose() == false) {
        timer.RunTimer(GetFPS());
        if (timer.getFrame() == 60) {
            ball.Accelerate(0.1);
        }

        ball.Collide(player1, player2);

        ball.Move();

        // Player collision and Input
        player1.Move(KeyboardKey(KEY_W), KeyboardKey(KEY_S));
        player2.Move(KeyboardKey(KEY_UP), KeyboardKey(KEY_DOWN));

        // Shape drawing
        BeginDrawing();

        if (powerUp.visible) {
            powerUp.Collide(ball);
            DrawTriangle(powerUp.v1, powerUp.v2, powerUp.v3, WHITE);

        } else if (timer.getSec() % 5 == 0){
            powerUp.Respawn();
        }

        ClearBackground(BLACK);

        DrawRectangleRec(player1.rect, WHITE);
        DrawRectangleRec(player2.rect, WHITE);

        DrawText(TextFormat("%d", player1.score), screen.w / 4, 40, 40, WHITE);
        DrawText(TextFormat("%d", player2.score), screen.w * 3 / 4, 40, 40, WHITE);

        DrawLine(screen.w / 2, 0, screen.w / 2, screen.h, WHITE);

        DrawCircle(ball.GetX(), ball.GetY(), ball.radius, WHITE);
    

        // Debug stuff
        DrawCircleV(player1.center, 3, RED);
        DrawCircleV(player2.center, 3, RED);
        DrawCircleV(powerUp.position, 3, RED);
        DrawCircleV(powerUp.v1, 3, GREEN);
        DrawCircleV(powerUp.v2, 3, BLUE);
        DrawCircleV(powerUp.v3, 3, PURPLE);

        DrawLine(0, screen.h / 2, screen.w, screen.h / 2, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
