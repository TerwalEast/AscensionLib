//
//  AL_Window.cpp
//  AscensionLib
//
//  Created by shan on 2021/2/25.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_Window.hpp"

SDL_Window* AL_Window::_pWindow;
SDL_Renderer* AL_Window::_pRenderer;
bool AL_Window::_isFullScreen;
double_t AL_Window::_height;
double_t AL_Window::_width;
std::string AL_Window::_headerText;



void AL_Window::InitWindow(std::string windowTitle, uint32_t height, uint32_t width)
{
    
    
    
    
    
    //创建SDL窗口和配套的渲染器。
    _pWindow = SDL_CreateWindow( windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    _pRenderer = SDL_CreateRenderer( _pWindow, -1, SDL_RENDERER_ACCELERATED );
    
    //抹个白色背景。SDL内部机制，每次调用SDL_RenderClear都会抹一遍当前RenderDrawColor的颜色。
    SDL_SetRenderDrawColor( _pRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    

    
    
}



SDL_Window* AL_Window::GetSDLWindow()
{
    return _pWindow;
}

SDL_Renderer* AL_Window::GetSDLRenderer()
{
    return _pRenderer;
}

void AL_Window::free()
{
    SDL_free(_pWindow);
    SDL_free(_pRenderer);
    
}
