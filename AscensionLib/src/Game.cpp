//
//  AL_Game.cpp
//  AscensionLib
//
//  Created by shan on 2021/3/7.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/Game.hpp"
#include "../include/AL_Window.hpp"



namespace AscensionLib {
constexpr int gl_major_version = 4;
constexpr int gl_minor_version = 1;
constexpr bool gl_debug = true;
//constexpr const char * window_title = "OpenGL 4.5 + SDL2 Basic window";
//constexpr int window_width = 1024;
//constexpr int window_height = 768;
constexpr bool fullscreen = false;
constexpr bool vsync = false;


void Init_SDL_GL()
{
    
    
    
    
    
}



void Game::InitGame(std::string windowTitle, uint32_t width, uint32_t height)
{
    //初始化SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL Init Success" << std::endl;
    }
    else
    {
        std::cout << "SDL Init Failed" << std::endl;
        exit(0);
    }
    
    //设置SDL采样率为默认
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    
    //焦点丢失时不最小化窗口
    SDL_SetHint( SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS, "0");
    
    //打包加速渲染（对于弹幕、格子棋盘等大量元素渲染至关重要）
    SDL_SetHint(SDL_HINT_RENDER_BATCHING, "1");
    
    //初始化SDL_IMG库
    IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG );
    
    TTF_Init();
    
    //通过SDL初始化OpenGL。
    Init_SDL_GL();
    
    //初始化AL_Window
    AL_Window::InitWindow(windowTitle, width, height);
    
    
    
    
    
    
    
    
    
    
}
}





