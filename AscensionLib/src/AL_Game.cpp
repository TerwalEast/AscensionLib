//
//  AL_Game.cpp
//  AscensionLib
//
//  Created by shan on 2021/3/7.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_Game.hpp"
#include "../include/AL_Window.hpp"

void AL_Game::InitGame(std::string windowTitle, uint32_t height, uint32_t width)
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
    
    //设置SDL采样率为默认，焦点丢失时不最小化窗口
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    SDL_SetHint( SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS, "0");
    
    //初始化SDL_IMG库
    IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG );
    
    //初始化AL_Window
    AL_Window::InitWindow(windowTitle, height, width);
    
    
    
    
    
}

