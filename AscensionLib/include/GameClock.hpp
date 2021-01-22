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
    
    static uint64_t LastTime;
    static uint64_t CurrentTime;
    static uint64_t ElapsedTime;

    
public:
    
    
    void UpdateTime();
    
    
    GameClock();
    ~GameClock();
    
    
    uint64_t GetElapsedTimeInMS()
    {
        return ElapsedTime;
    };
    
    
    
};


#endif /* gameClock_hpp */
