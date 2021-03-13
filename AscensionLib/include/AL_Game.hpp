//
//  AL_Game.hpp
//  AscensionLib
//
//  Created by shan on 2021/3/7.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef AL_Game_hpp
#define AL_Game_hpp

#include <stdio.h>

class AL_Game
{
    
public:
    
    static AL_Game& AL_GetGame()
    {
        return _game;
    }
    
    static void InitGame();
    
    static void HandleInput();
    
    static void UpdateGame();
    
    static void RenderGame();
    
private:
    
    AL_Game(){};
    ~AL_Game(){};
    AL_Game(const AL_Game& game) = delete;
    AL_Game& operator = (const AL_Game game) = delete;
    
    
    
    
    static AL_Game _game;
    
};




#endif /* AL_Game_hpp */
