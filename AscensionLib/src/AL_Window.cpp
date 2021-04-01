//
//  AL_Window.cpp
//  AscensionLib
//
//  Created by shan on 2021/2/25.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_Window.hpp"
#include "../include/AL_Texture.hpp"

SDL_Window* AL_Window::_pWindow;
SDL_Renderer* AL_Window::_pRenderer;
bool AL_Window::_isFullScreen;
int AL_Window::_height;
int AL_Window::_width;
std::string AL_Window::_headerText;
uint AL_Window::R;
uint AL_Window::G;
uint AL_Window::B;
uint AL_Window::A;

void AL_Window::SetLogicalResolution(int width, int height)
{
    SDL_RenderSetLogicalSize(_pRenderer, width, height);
}


void AL_Window::SetBackgroundColour(uint r, uint g, uint b, uint a)
{
    R = r;
    G = g;
    B = b;
    A = a;
    SDL_SetRenderDrawColor(_pRenderer, R, G, B, A);
    
}


void AL_Window::ClearWindow()
{
    SDL_Rect fullRect = { 0, 0, _width, _height};
    SDL_RenderClear(_pRenderer);
    SDL_RenderFillRect(_pRenderer, &fullRect);
    
}


void AL_Window::FlushRenderer()
{
    SDL_RenderFlush(_pRenderer);
}

void AL_Window::ShowCurrent()
{
    SDL_RenderPresent(_pRenderer);
}


void AL_Window::InitWindow(std::string windowTitle, uint32_t width, uint32_t height)
{
    
    _height = height;
    _width = width;
    
    //创建SDL窗口和配套的渲染器。
    _pWindow = SDL_CreateWindow( windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    _pRenderer = SDL_CreateRenderer( _pWindow, -1, SDL_RENDERER_ACCELERATED );
    
    A = 0xFF;
    B = 0xFF;
    G = 0xFF;
    R = 0xFF;
    
    //抹个白色背景。SDL内部机制，每次调用SDL_RenderClear都会抹一遍当前RenderDrawColor的颜色。
    SDL_SetRenderDrawColor( _pRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    
    
}

void AL_Texture::SetAlphaMode(uint alpha)
{
    SDL_SetTextureAlphaMod(_pTargetTexture.get(), alpha);
}




void AL_Window::free()
{
    SDL_DestroyRenderer(_pRenderer);
    SDL_DestroyWindow(_pWindow);
}
