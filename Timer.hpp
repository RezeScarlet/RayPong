// ! Comenta o codigo Yagoooo
#include <raylib.h>
#include <string>
class Timer{

private:
    int frame;
    int sec;
    int min;

    bool stop;
public:
    
    Timer();
    void RunTimer(int FPS);
    void stopTimer(bool stop);
    void resetTimer(bool reset);
    std::string toString();

    int getFrame();
    int getSec();
    int getMin();
};

inline Timer::Timer(){
    frame = 0;
    sec = 0;
    min = 0;
}

inline void Timer::RunTimer(int FPS){
    if(!stop){
        frame++;
        if(frame >= FPS){
            sec++;
            frame = 0;
        }
        if(sec == 60){
            min++;
            sec = 0;
        }
    }
}

inline void Timer::stopTimer(bool stop){
    this->stop = stop;
}

inline void Timer::resetTimer(bool reset){
    frame = 0;
    sec = 0;
    min = 0;
}

inline std::string Timer::toString(){
    std::string sFrame = std::to_string(frame);
    std::string sSeg = std::to_string(sec);
    std::string sMin = std::to_string(min);
    std::string finalString = TextFormat("Min: %d\nSec: %d\nFrame: %d\n", min, sec, frame);
    return finalString;
}

inline int Timer::getFrame() {
    return frame;
}

inline int Timer::getSec() {
    return sec;
}

inline int Timer::getMin() {
    return min;
}
