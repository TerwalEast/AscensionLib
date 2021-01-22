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
uint64_t GameClock::ElapsedTime;

void GameClock :: UpdateTime()
{
    CurrentTime = SDL_GetPerformanceCounter();
    ElapsedTime = (CurrentTime - LastTime) / SDL_GetPerformanceFrequency();
    LastTime = CurrentTime;
};


GameClock :: GameClock()
{
    LastTime = 0;
};
