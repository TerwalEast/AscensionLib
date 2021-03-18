//
//  Splash.cpp
//  AscensionLib
//
//  Created by shan on 2021/2/27.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "Splash.hpp"
#include "GameManager.hpp"

#define SPLASH_TEXTURE_ID "splash_texture"
#define SPLASH_FILE_PATH "/Users/shan/Desktop/AscensionLib/AscensionLib/Resources/EoSD/th06logo.jpg"



void Splash::InitSplash()
{
    string id = SPLASH_TEXTURE_ID;
    string filePath = SPLASH_FILE_PATH;
    AL_ResourceManager::LoadTexture(filePath, id);
    
    
    
}


void Splash::SplashLoop()
{
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    int alpha;
    double timeStack = 0;

    AL_GameClock::UpdateTime();
    AL_GameClock::GetElapsedTime();

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

        

        
    //涂个白色（0x00,0x00,0x00）不透明（0xFF）底。之前设置了Texture混合模式为Blend，这个底将会和我们的材质Blend达到渐变效果
        AL_Window::ClearWindow();

        //调用钟表获取时间，根据时间改变当前的状态
        AL_GameClock::UpdateTime();
        timeStack += AL_GameClock::GetElapsedTime();
        alpha = floor(timeStack / 2.0 * 255);

        _pSplashTexture->SetAlphaMode(alpha);

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
    
    
    
    
    
    
    
    
    
    
    
    GameManager::_gameState = GameManager::Playing;
}


void Splash::_destorySplashTexture()
{
    string id = SPLASH_TEXTURE_ID;
    AL_ResourceManager::ClearFromTextureMap(id);
    
    
    
    
}
