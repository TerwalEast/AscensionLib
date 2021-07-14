//
//  AL_InputHandler.cpp
//  AscensionLib
//
//  Created by shan on 2021/4/1.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_InputHandler.hpp"
#include "../include/Util.hpp"

using namespace AscensionLib;

AL_InputHandler AL_InputHandler::_inputHandler;

AL_InputHandler::AL_InputHandler()
{
    m_mousePosition = new Vector2D();
};

AL_InputHandler::~AL_InputHandler()
{
    
};

void AL_InputHandler::Update()
{
    int x,y;
    
    SDL_GetMouseState(&x, &y);
    
    m_mousePosition->x = x;
    m_mousePosition->y = y;
    
    std::cout << x << " " << y << std::endl;
}


