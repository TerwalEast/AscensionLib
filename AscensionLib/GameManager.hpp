//
//  GameManager.hpp
//  AscensionLib
//
//  Created by shan on 2021/2/21.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include <vector>
#include "AeroPlaneGame.hpp"


class Player;
class ChessBoard;

class Splash;

class GameManager
{
public:
    

    
    static void InitGame();
    static AL_Window& GetWindow();
    static AL_GameObjectManager& GetGameObjectManager();
    GameManager();
    ~GameManager();
    
    friend class Splash;

private:
    
    static bool _closeGame();
    static void _mainLoop();
    static void _initRelativePaths();
    static void _menuLoop();
    static void _splashLoop();
    static void _gameLoop();

    enum GameState { Uninitialized, ShowingSplash, ShowingMenu, Playing, Exiting };

    static GameState _gameState;
    static AL_Window _gameWindow;
    static AL_GameClock _localClock;
    
    
    enum gameStatus{ init, playing, onturn};
    
    static gameStatus GameStatus;
    

    
    int _rollDice();
    

    
};



#endif /* GameManager_hpp */
