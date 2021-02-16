//
//  gameClock.hpp
//  STG_Demo
//
//  Created by shan on 2021/1/18.
//  Copyright © 2021 Terwal. All rights reserved.
//

#ifndef gameClock_hpp
#define gameClock_hpp

#include "STG.hpp"


class GameClock
{
    
private:
    
    static double_t LastTime;
    static double_t CurrentTime;
    static double_t SystemFrequency;
    static double_t ElapsedTime;

    
public:
    
    

    //更新当前的时间，并获得一个新的ElapsedTime（两帧之间经过时间）
    void UpdateTime();
    
    
    GameClock();
    
    ~GameClock();
    
    
    double_t GetElapsedTime()
    {
        return ElapsedTime;
    };
    

    
    
    
};


#endif /* gameClock_hpp */
