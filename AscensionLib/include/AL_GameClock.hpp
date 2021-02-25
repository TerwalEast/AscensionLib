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


class AL_GameClock
{
    
private:
    
    //上一次取时间时，系统的记时刻数量
    static uint64_t LastTick;
    
    //这次取时间时系统的刻数量
    static uint64_t CurrentTick;
    
    //此系统每秒的刻数
    static uint64_t SystemFrequency;
    
    //上次取的时间
    static double_t LastTime;
    
    //这次取的时间
    static double_t CurrentTime;
    
    //两次取时之间的时间，用double存储。
    static double_t ElapsedTime;

    
public:
    
    

    //更新当前的时间，更新一个新的ElapsedTime（两帧之间经过时间）
    void UpdateTime();
    
    //构造
    AL_GameClock();
    
    //析构
    ~AL_GameClock();
    
    //获取ElapsedTime
    double_t GetElapsedTime()
    {
        return ElapsedTime;
    };
    

    
    
    
};


#endif /* gameClock_hpp */
