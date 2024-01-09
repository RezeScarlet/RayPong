#include <iostream>
#include <string>

class Timer{

private:
    int frame;

    bool stop;
public:
    int seg;
    int min;

    Timer();
    ~Timer();
    void startTimer(int FPS);
    void stopTimer(bool stop);
    void resetTimer(bool reset);
    std::string toString();
};

Timer::Timer(){
    frame = 0;
    seg = 0;
    min = 0;
}

Timer::~Timer(){
}

void Timer::startTimer(int FPS){
    if(!stop){
        frame++;
        if(frame >= FPS){
            seg++;
            frame = 0;
        }
        if(seg == 60){
            min++;
            seg = 0;
        }
    }
}

void Timer::stopTimer(bool stop){
    this->stop = stop;
}

void Timer::resetTimer(bool reset){
    frame = 0;
    seg = 0;
    min = 0;
}

std::string Timer::toString(){
    std::string sFrame = std::to_string(frame);
    std::string sSeg = std::to_string(seg);
    std::string sMin = std::to_string(min);
    std::string finalString = min + "/ " + seg + "/ " + frame;
    return finalString;
}