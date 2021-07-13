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

void AL_InputHandler::AL_InputHandler()
{
    
};

void AL_InputHandler::~AL_InputHandler()
{
    m_mousePosition = new AL_Vector2D();
};

void AL_InputHandler::Update()
{
    SDL_GetMouseState(&m_mousePosition.x, &m_mousePosition.y);
}


