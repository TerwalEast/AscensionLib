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


class GameManager
{
public:
    
    static void InitGame();
    static SDL_Window& GetWindow();
    static SDL_Renderer& GetRenderer();
    static GameObjectManager& GetGameObjectManager();
    GameManager();
    ~GameManager();

private:
    
    static bool _closeGame();
    static void _mainLoop();
    static void _initRelativePaths();
    static void _menuLoop();
    static void _splashLoop();
    static void _gameLoop();

    enum GameState { Uninitialized, ShowingSplash, ShowingMenu, Playing, Exiting };

    static GameState _gameState;
    static SDL_Window* _mainWindow;
    static SDL_Renderer* _mainRenderer;
    static GameClock _localClock;
    
    
    enum gameStatus{ init, playing, onturn};
    
    static gameStatus GameStatus;
    
    std::vector<Player> _playerList;
    static ChessBoard _chessBoard;
    
    static SDL_Texture* _chessBoardTexture;
    static SDL_Texture* _splashTexture;
    static SDL_Texture* _pieceTexture;
    
    
    static SDL_Texture* _loadTexture(std::string path);
    
    
    static int _rollDice();
    

    
};



#endif /* GameManager_hpp */
