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

class AL_GameObjectManager;

class Game
{
public:
    
    
    
    static void InitGame();
    static SDL_Window& GetWindow();
    static SDL_Renderer& GetRenderer();
    static AL_GameObjectManager& GetGameObjectManager();
    

private:
    static bool _closeGame();
    static void _mainLoop();
    //static void _initRelativePaths();
//    static void ShowSplashScreen();
//    static void ShowMenu();

    enum GameState { Uninitialized, ShowingSplash, Paused,
                    ShowingMenu, Playing, Exiting };

    
    static GameState _gameState;
    static SDL_Window _mainWindow;
    static SDL_Renderer _mainRenderer;
    static AL_GameObjectManager _gameObjectManager;
    
    
    
};



#endif /* game_hpp */
