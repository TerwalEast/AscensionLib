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
    
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        
        
        
    }
    else
    {
        
        
    }
    
    
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    
    
    _pWindow = SDL_CreateWindow( windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN );
    _pRenderer = SDL_CreateRenderer( _pWindow, -1, SDL_RENDERER_ACCELERATED );
    SDL_SetRenderDrawColor( _pRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    
    IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG );
    
    
}



AL_Window::AL_Window()
{
    
    
}


AL_Window::~AL_Window()
{
    free();
    
    
}


void AL_Window::free()
{
    SDL_free(_pWindow);
    SDL_free(_pRenderer);
    
}
