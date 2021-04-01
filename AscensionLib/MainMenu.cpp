//
//  MainMenu.cpp
//  AscensionLib
//
//  Created by shan on 2021/3/5.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "MainMenu.hpp"

MenuSelection::MenuSelection(string targetNormalTextureID, string targetHighlightTextureID, AL_Rectangle renderTargetArea, AL_Rectangle ClipArea)
{
    _targetNormalTexture = AL_ResourceManager::GetTextureByID(targetNormalTextureID);
    _targetHightLightTexture = AL_ResourceManager::GetTextureByID(targetHighlightTextureID);
    _renderTargetArea = renderTargetArea;
    _clipArea = ClipArea;
}



void MainMenu::MainMenuLoop()
{
    SDL_Event e;
    bool quit = false;
    
    while(!quit)
    {
        
        
        
        AL_Window::ClearWindow();
        _pTextureMenuBackground->DirectRender();
        AL_Window::ShowCurrent();
        //std::cout << "WTF" << std::endl;
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }
    }
    
    
    
}

MainMenu::MainMenu()
{
    //读取材质。这可真不少啊！
    _pTextureMenuBackground = AL_ResourceManager::LoadTexture(MAIN_MENU_BACKGROUND_PATH, MAIN_MENU_BACKGROUND_ID);
    
    
    
    
    
}



MainMenu::~MainMenu()
{
    
}



