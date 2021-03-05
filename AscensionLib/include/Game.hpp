//
//  game.hpp
//  STG_Demo
//
//  Created by shan on 2021/1/17.
//  Copyright © 2021 Terwal. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include "STG.hpp"
#include "Util.hpp"
#include "AL_Window.hpp"

class AL_GameObjectManager;

class Game
{
public:
    
    
    static void InitGame();
    static AL_Window& GetWindow();
    static AL_GameObjectManager& GetGameObjectManager();
    

private:
    
    static AL_Window _gameWindow;
    static AL_GameObjectManager _gameObjectManager;
    
    
    
};



#endif /* game_hpp */
