//
//  gameClock.cpp
//  STG_Demo
//
//  Created by shan on 2021/1/18.
//  Copyright © 2021 Terwal. All rights reserved.
//

#include "../include/GameClock.hpp"

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




uint64_t GameClock::CurrentTime;
uint64_t GameClock::LastTime;
double_t GameClock::ElapsedTime;
uint64_t GameClock::SystemFrequency;

GameClock :: GameClock()
{
    SystemFrequency = SDL_GetPerformanceFrequency();
    LastTime = 0;
    UpdateTime();
}


void GameClock :: UpdateTime()
{
    CurrentTime = SDL_GetPerformanceCounter();
    ElapsedTime = (double)(CurrentTime - LastTime) / (double)SystemFrequency;
    LastTime = CurrentTime;
};

GameClock :: ~GameClock()
{
    
}


