#include <raylib.h>
class Screen {
public:
  static float h;
  static float w;
  void UpdateResolution();
  Screen();
};

// float Screen::h;
// float Screen::w;

inline void Screen::UpdateResolution() {
  h = GetScreenHeight();
  w = GetScreenWidth();
}

inline Screen::Screen() {
  h = GetScreenHeight();
  w = GetScreenWidth();
}
