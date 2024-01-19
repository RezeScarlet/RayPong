// ! Comenta o codigo Yagoooo
#include <raylib.h>
#include <string>
class Timer{

private:
    int frame;

    bool stop;
public:
    int sec;
    int min;

    Timer();
    ~Timer();
    void startTimer(int FPS);
    void stopTimer(bool stop);
    void resetTimer(bool reset);
    std::string toString();
};

inline Timer::Timer(){
    frame = 0;
    sec = 0;
    min = 0;
}

inline void Timer::startTimer(int FPS){
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
