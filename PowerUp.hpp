class PowerUp {
public:

    // receives the triangle coordenate and
    Vector2 position = {(float)GetScreenWidth()/2+200, (float)GetScreenHeight()/2};
    Vector2 v1 = {position.x,position.y-((float)sqrt(3)/2)*200};
    Vector2 v2 = {position.x-100,position.y};
    Vector2 v3 = {position.x+100,position.y};
};
