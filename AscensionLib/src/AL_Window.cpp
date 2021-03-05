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



void AL_Window::InitWindow()
{
    
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    
    
    _mainWindow = SDL_CreateWindow( "Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    _mainRenderer = SDL_CreateRenderer( _mainWindow, -1, SDL_RENDERER_ACCELERATED );
    SDL_SetRenderDrawColor( _mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    IMG_Init( IMG_INIT_JPG | IMG_INIT_PNG );
    
    _pWindow = SDL_CreateWindow(<#const char *title#>, <#int x#>, <#int y#>, <#int w#>, <#int h#>, <#Uint32 flags#>);
    _pRenderer = SDL_CreateRenderer(<#SDL_Window *window#>, <#int index#>, <#Uint32 flags#>);
    
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
