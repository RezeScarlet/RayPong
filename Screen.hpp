#include <raylib.h>
class Screen {
public:
  static float h;
  static float w;
  void UpdateResolution();
  Screen();
};
// Needs this to compile on Windows (I don't know the fuck why)
float Screen::h = GetScreenHeight();
float Screen::w = GetScreenWidth();

inline void Screen::UpdateResolution() {
  h = GetScreenHeight();
  w = GetScreenWidth();
}

inline Screen::Screen() {
  h = GetScreenHeight();
  w = GetScreenWidth();
}
