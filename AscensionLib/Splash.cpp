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

Splash::Splash()
{
    
    string id = SPLASH_TEXTURE_ID;
    string filePath = SPLASH_FILE_PATH;
    
    AL_ResourceManager::LoadTexture(filePath, id);

    _SplashTexture = AL_ResourceManager::GetTextureByID(id);
}






void Splash::SplashLoop()
{
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    int alpha = 0;
    double timeStack = 0;

    AL_GameClock::UpdateTime();
    AL_GameClock::GetElapsedTime();
    AL_Window::SetBackgroundColour(255, 255, 255, 255);

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

        


        //涂个白色（0xFF,0xFF,0xFF）透明（0xFF）底。之前设置了Texture混合模式为Blend，这个底将会和我们的材质Blend达到渐变效果
        AL_Window::ClearWindow();

        //调用钟表获取时间，根据时间改变当前的状态
        AL_GameClock::UpdateTime();
        timeStack += AL_GameClock::GetElapsedTime();
        alpha = floor(timeStack / 2.0 * 255);

        cout << "current alpha: " << alpha << endl;
        cout << "current timeStack: " << timeStack << endl;

        _SplashTexture->SetAlphaMode(alpha);

        //把材质渲染到屏幕上
        _SplashTexture->DirectRender();


        //更新屏幕
        AL_Window::ShowCurrent();

        if(timeStack >= 2) break;

    }
    //保持
    timeStack = 0;
    AL_GameClock::UpdateTime();
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

        AL_GameClock::UpdateTime();

        timeStack += AL_GameClock::GetElapsedTime();
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
        AL_Window::ClearWindow();

        //调用钟表获取时间，根据时间改变当前的状态
        AL_GameClock::UpdateTime();
        timeStack += AL_GameClock::GetElapsedTime();
        alpha = 255 - floor(timeStack / 2.0 * 255);

        cout << "current alpha: " << alpha << endl;

        _SplashTexture->SetAlphaMode(alpha);

        //把材质渲染到屏幕上
        _SplashTexture->DirectRender();

        //更新屏幕
        AL_Window::ShowCurrent();

        if(timeStack >= 2) break;

    }
    
    
    GameManager::_gameState = GameManager::ShowingMenu;
    

}


void Splash::_destorySplashTexture()
{
    string id = SPLASH_TEXTURE_ID;
    AL_ResourceManager::ClearFromTextureMap(id);
    
    
    
    
}
