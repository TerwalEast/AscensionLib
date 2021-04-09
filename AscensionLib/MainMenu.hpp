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

/**
 *我想应该主菜单写成硬编码没什么问题吧.......
 *仍然在用直接路径获取资源，这样不好，等我改出合适的资源管理器。
 *
 *
 *
 */

class MainMenu;

//菜单选项。就是例如“Start Game”、“Option”这样的一个选项。
class MenuSelection : AL_VisibleObject
{
public:
    
    MenuSelection(string targetNormalTextureID, string targetHighlightTextureID, AL_Rectangle renderTargetArea, AL_Rectangle ClipArea);
    ~MenuSelection();
    
    void Draw();
    
    void Update()
    {
        
    };
    
    
    void destory()
    {
        
    };
    
    
private:
    
    AL_Rectangle _renderTargetArea;
    AL_Rectangle _clipArea;
    AL_Texture* _ptargetNormalTexture;
    AL_Texture* _ptargetHightLightTexture;
    
    MainMenu* _pMyMenu;
};

class MainMenu
{
    
public:
    
    MainMenu();
    ~MainMenu();
    
    
    void MainMenuLoop();
    
    void RenderSelections();
    
    
private:
    
    //坐着的.jpg
    AL_Texture* _pTextureMenuBackground;
    std::vector<MenuSelection> _selectionVector;
    
    
    
    
};



#endif /* MainMenu_hpp */
