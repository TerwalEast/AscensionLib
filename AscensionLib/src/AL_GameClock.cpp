//
//  gameClock.cpp
//  STG_Demo
//
//  Created by shan on 2021/1/18.
//  Copyright © 2021 Terwal. All rights reserved.
//

#include "../include/AL_GameClock.hpp"

//class GameClock
//{
//
//private:
//
//    static uint64_t LastTime;
//    static uint64_t CurrentTime;
//    static uint64_t ElapsedTimeInMS;
//
//
//public:
//
//
//    void UpdateTime();
//
//
//    GameClock();
//    ~GameClock();
//
//
//    uint_64 GetElapsedTimeInMS()
//    {
//        return ElapsedTimeInMS;
//    };
//
//
//
//};




uint64_t AL_GameClock::CurrentTick;
uint64_t AL_GameClock::LastTick;
double_t AL_GameClock::CurrentTime;
double_t AL_GameClock::LastTime;
double_t AL_GameClock::ElapsedTime;
uint64_t AL_GameClock::SystemFrequency;

AL_GameClock :: AL_GameClock()
{
    SystemFrequency = SDL_GetPerformanceFrequency();
    
    LastTick = SDL_GetPerformanceCounter();
    
    CurrentTick = LastTick;
    
    LastTime = (double)(LastTick) / (double)SystemFrequency;
    CurrentTime = LastTime;
    
    UpdateTime();
}


void AL_GameClock :: UpdateTime()
{
    LastTick = CurrentTick;
    LastTime = CurrentTime;
    
    CurrentTick = SDL_GetPerformanceCounter();
    
    CurrentTime = (double)(CurrentTick) / (double)SystemFrequency;
    
    ElapsedTime = CurrentTime - LastTime;
};

AL_GameClock :: ~AL_GameClock()
{
    
}


