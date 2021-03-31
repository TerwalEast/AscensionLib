//
//  MainMenu.hpp
//  AscensionLib
//
//  Created by shan on 2021/3/5.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <stdio.h>
#include "AeroPlaneGame.hpp"

class MainMenu
{
    
public:
    
    MainMenu();
    ~MainMenu();
    
    
    bool InitMainMenu();
    
    void MainMenuLoop();
    
    
    
private:
    
    
    AL_Texture* _pTextureMenuBackground;
    
    AL_Texture* _pTextureMenuSelectionHighlight;
    AL_Texture* _pTextureMenuSelectionOutline;
    AL_Texture* _pTextureMenuSelectionText;
    
    AL_Texture* _pTextureMenuTitleOutline;
    AL_Texture* _pTextureMenuTitle;
    
    AL_Texture* _pTextureMenuHongOutline;
    AL_Texture* _pTextureMenuHong;
    
    
    
    
};



#endif /* MainMenu_hpp */
