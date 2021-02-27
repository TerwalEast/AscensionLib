//
//  AL_Texture.hpp
//  AscensionLib
//
//  Created by shan on 2021/1/27.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef AL_Texture_hpp
#define AL_Texture_hpp

#include <stdio.h>
#include "STG.hpp"
#include <string>
#include "Util.hpp"

class AL_Window;
/*
A AL_Texture is a local warped SDL_Texture, to support object-oriented programming. It provides a univeral construct/deconstruct API, plus automatically allocator.
Please note that texture should be used to store 2^ size graphic resources, otherwise the graphic memory is wasted. Make atlas before loading as actual textures, and render them using clip() method.
 */




class AL_Texture
{
public:
    
    //构造
    AL_Texture();
    
    //析构
    ~AL_Texture();
    
    //从文件中读取材质
    void Load(std::string path);
    
    //摧毁这个材质类，释放它占用的空间
    void Destroy();
    
    //渲染方法，指定左上角坐标系
    void Render(float x, float y);
    
    void Render(float x, float y, float width, float height);
    
    
    
    void AssignWindow();
    
    
private:
    
    //被封装的实际SDL材质
    SDL_Texture *_targetTexture;
    SDL_Renderer *_targetRenderer;
    
};




#endif /* AL_Texture_hpp */
