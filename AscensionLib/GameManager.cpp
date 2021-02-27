//
//  GameManager.cpp
//  AscensionLib
//
//  Created by shan on 2021/2/21.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "GameManager.hpp"
#include "AeroPlaneGame.hpp"
#include "Player.hpp"
#include "ChessBoard.hpp"
#include "Splash.hpp"

#define SCREEN_HEIGHT 612
#define SCREEN_WIDTH 612

using namespace std;

GameManager :: GameState GameManager :: _gameState;
AL_GameClock GameManager :: _localClock;
ChessBoard GameManager::_chessBoard;
SDL_Window* GameManager :: _mainWindow;
SDL_Renderer* GameManager :: _mainRenderer;
SDL_Texture* GameManager :: _splashTexture;
SDL_Texture* GameManager :: _chessBoardTexture;
SDL_Texture* GameManager::_pieceTexture;

SDL_Texture* GameManager :: _loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( _mainRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);
    
    return newTexture;
}

int _rollDice()
{
    return rand()%6 + 1;
}



void GameManager :: _splashLoop()
{
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    int alpha;
    double timeStack = 0;

    _localClock.UpdateTime();
    _localClock.GetElapsedTime();

    //淡入
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Clear screen
        SDL_RenderClear( _mainRenderer );

        
        //涂个白色（0x00,0x00,0x00）不透明（0xFF）底。之前设置了Texture混合模式为Blend，这个底将会和我们的材质Blend达到渐变效果
        SDL_Rect fillRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
        SDL_SetRenderDrawColor( _mainRenderer, 0x00, 0x00, 0x00, 0xFF );
        SDL_RenderFillRect( _mainRenderer, &fillRect );

        //调用钟表获取时间，根据时间改变当前的状态
        _localClock.UpdateTime();
        timeStack += _localClock.GetElapsedTime();
        alpha = floor(timeStack / 2.0 * 255);


        SDL_SetTextureAlphaMod(_splashTexture, alpha);

        std::cout << alpha << std::endl;

        //把材质渲染到屏幕上
        SDL_RenderCopy( _mainRenderer, _splashTexture, NULL, NULL );

        //更新屏幕
        SDL_RenderPresent( _mainRenderer );

        if(timeStack >= 2) break;

    }
    
    //保持
    timeStack = 0;
    _localClock.UpdateTime();
    while( !quit )
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }
        
        
        
        _localClock.UpdateTime();
        timeStack += _localClock.GetElapsedTime();
        if(timeStack >= 1) break;
        
    }
    
    //淡出
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Clear screen
        SDL_RenderClear( _mainRenderer );

        SDL_Rect fillRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
        SDL_SetRenderDrawColor( _mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderFillRect( _mainRenderer, &fillRect );

        //调用钟表获取时间，根据时间改变当前的状态
        _localClock.UpdateTime();
        timeStack += _localClock.GetElapsedTime();
        alpha = 255 - floor(timeStack / 2.0 * 255);


        SDL_SetTextureAlphaMod(_splashTexture, alpha);

        std::cout << alpha << std::endl;

        //把材质渲染到屏幕上
        SDL_RenderCopy( _mainRenderer, _splashTexture, NULL, NULL );

        //更新屏幕
        SDL_RenderPresent( _mainRenderer );

        if(timeStack >= 2) break;

    }
    
    
    _gameState = ShowingMenu;
    
}

void GameManager :: _gameLoop()
{
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
}

void GameManager :: _menuLoop()
{
    
    _gameState = Playing;
}


GameManager :: GameManager()
{
    
}

GameManager :: ~GameManager()
{
    
}

void GameManager :: InitGame()
{
    //初始化SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    _mainWindow = SDL_CreateWindow( "Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    _mainRenderer = SDL_CreateRenderer( _mainWindow, -1, SDL_RENDERER_ACCELERATED );
    SDL_SetRenderDrawColor( _mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG );
    
    //初始化游戏机制
    srand((unsigned)time(NULL));
    
    _localClock.UpdateTime();
    
    
    
    
    
    
    //读取资源
    _splashTexture = _loadTexture("/Users/shan/Desktop/AscensionLib/AscensionLib/Resources/EoSD/th06logo.jpg");
    
    _chessBoardTexture = _loadTexture("/Users/shan/Desktop/AscensionLib/AscensionLib/Resources/Aeroplane/unnamed.png");
    
    _pieceTexture = _loadTexture("/Users/shan/Desktop/AscensionLib/AscensionLib/Resources/Aeroplane/P.png");
    
    
    
    //进入主循环
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
