//
//  MainMenu.cpp
//  AscensionLib
//
//  Created by shan on 2021/3/5.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "MainMenu.hpp"

using namespace AscensionLib;

void MenuSelection::Draw()
{
    if(_isSelected)
    {
        _ptargetHightLightTexture->DirectRender(_renderTargetArea, _clipArea);
    }
    else
    {
        _ptargetNormalTexture->DirectRender(_renderTargetArea, _clipArea);
    }
}



MenuSelection::MenuSelection(AscensionLib::AL_Texture* normalTexture,AscensionLib::AL_Texture* highlightTexture, AscensionLib::Rectangle renderTargetArea, AscensionLib::Rectangle clipArea, MainMenu* pMenu)
{
    _pMyMenu = pMenu;
    _renderTargetArea = renderTargetArea;
    _clipArea = clipArea;
    _ptargetNormalTexture = normalTexture;
    _ptargetHightLightTexture = highlightTexture;
    _isSelected = false;
    
}



void MainMenu::MainMenuLoop()
{
    SDL_Event e;
    bool quit = false;
    
    while(!quit)
    {
        AscensionLib::AL_InputHandler::GetInputHandler().Update();
        AscensionLib::AL_Window::ClearWindow();
        _pTextureMenuBackground->DirectRender();
        AscensionLib::AL_Window::ShowCurrent();
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
    _pTextureMenuBackground = AscensionLib::AL_ResourceManager::LoadTexture(MAIN_MENU_BACKGROUND_PATH, MAIN_MENU_BACKGROUND_ID);
    //_pTextNormalTexture = AL_ResourceManager::LoadTexture(std::string filePath, std::string textureID);
    
}



MainMenu::~MainMenu()
{
    
}



