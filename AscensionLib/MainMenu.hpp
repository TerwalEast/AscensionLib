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
 *--7.11:至少现在有获取bundle路径的办法了。但合适的带handle的资源管理器仍需要开发。
 *
 *
 */

class MainMenu;

//菜单选项。就是例如“Start Game”、“Option”这样的一个选项。
class MenuSelection : AL_VisibleObject
{
public:
    
    MenuSelection(string targetNormalTextureID, string targetHighlightTextureID, AscensionLib::Rectangle renderTargetArea, Rectangle clipArea, MainMenu* pMenu);
    ~MenuSelection()
    {
        
    };
    
    void Draw();
    
    void Update()
    {
        
    };
    
    
    void destory()
    {
        
    };
    
    
private:
    
    AscensionLib::Rectangle _renderTargetArea;
    AscensionLib::Rectangle _clipArea;
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
    
    AL_Texture* _pTextNormalTexture;
    AL_Texture* _pTextHighlightTexture;
    
    
    
};



#endif /* MainMenu_hpp */
