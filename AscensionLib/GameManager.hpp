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
class MainMenu;


class GameManager
{
public:
    

    friend Splash;
    
    static void InitGame();
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
    
    enum gameStatus{ init, playing, onturn};
    
    
    

    
    int _rollDice();
    

    
};



#endif /* GameManager_hpp */
