class Screen {
public:
    static float h;
    static float w;
    void UpdateResolution();
    Screen();
};

    float Screen::h;
    float Screen::w;

void Screen::UpdateResolution() {
    h = GetScreenHeight();
    w = GetScreenWidth();
}

Screen::Screen() {
    h = GetScreenHeight();
    w = GetScreenWidth();
}
