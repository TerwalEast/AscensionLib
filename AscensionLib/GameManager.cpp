//
//  GameManager.cpp
//  AscensionLib
//
//  Created by shan on 2021/2/21.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "GameManager.hpp"
#include "AeroPlaneGame.hpp"
#include "Splash.hpp"
#include "MainMenu.hpp"


#define SCREEN_HEIGHT 612
#define SCREEN_WIDTH 612

using namespace std;

GameManager::GameState GameManager::_gameState;





int _rollDice()
{
    return rand()%6 + 1;
}



void GameManager :: _splashLoop()
{
    Splash splash;
    splash.SplashLoop();
}

void GameManager :: _gameLoop()
{
    
    /*
    std::cout << "Game On" << std::endl;

    SDL_Event e;
    
    SDL_RenderClear(_mainRenderer);
    
    SDL_RenderCopy(_mainRenderer, _chessBoardTexture, NULL, NULL);
    
    SDL_RenderPresent(_mainRenderer);
    
    bool quit = false;
    
    while(!quit)
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }
        
        
        
        
        
        
    }
    
    
    
    
    std::cout << "Reaching the end" << std::endl;
    std::cout << "Reaching the end" << std::endl;
    _gameState = Exiting;
     
     */
    
    //_gameState = Exiting;
}

void GameManager :: _menuLoop()
{
    MainMenu mainMenu;
    mainMenu.MainMenuLoop();
}


GameManager :: GameManager()
{
    
}

GameManager :: ~GameManager()
{
    
}

void GameManager::InitGame()
{
    std::string title;
    title = "Demo";
    //AL_Window::InitWindow(title, 800, 600);
    
    AL_Game::InitGame(title, 600, 400);
    AL_GameClock::InitClock();
    
    //AL_Window::SetLogicalResolution(1600, 900);
    
    //进入Splash循环
    _gameState = ShowingSplash;
    
    _mainLoop();
    
}


void GameManager :: _mainLoop()
{
    
    
    
    while(1)
    {
        switch (_gameState) {
            case Uninitialized:
                InitGame();
                break;
                
            case ShowingSplash:
                _splashLoop();
                break;
                
            case Playing:
                _gameLoop();
                break;
                
            case ShowingMenu:
                _menuLoop();
                break;
                
            case Exiting:
                return;
                
            default:
                break;
        }
        
        
    }
    
    
    
    
    
    
    
    
}



/*
 
class GameManager
{
public:
    
    static void InitGame();
    static SDL_Window& GetWindow();
    static SDL_Renderer& GetRenderer();
    static GameObjectManager& GetGameObjectManager();
        

private:
    
    static bool _closeGame();
    static void _mainLoop();
    static void _initRelativePaths();

    enum GameState { Uninitialized, ShowingSplash, Playing, Exiting };

    static GameState _gameState;
    static SDL_Window _mainWindow;
    static SDL_Renderer _mainRenderer;
    
    
    
    enum gameStatus{ init, playing, onturn};
    
    static gameStatus GameStatus;
    
    std::vector<Player> _playerList;
    
    
    GameManager(int playerNumber);
    ~GameManager();
    
    int _rollDice();
    

    
};

*/
