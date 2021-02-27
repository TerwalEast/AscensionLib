//
//  AL_Window.cpp
//  AscensionLib
//
//  Created by shan on 2021/2/25.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_Window.hpp"

SDL_Window* AL_Window::_window;
SDL_Renderer* AL_Window::_renderer;


AL_Window::AL_Window()
{
    
    
}


AL_Window::~AL_Window()
{
    free();
    
    
}


void AL_Window::free()
{
    SDL_free(_window);
    SDL_free(_renderer);
    
}
