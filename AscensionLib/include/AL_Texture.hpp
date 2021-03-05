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
#include "AL_Camera.hpp"

class AL_Window;
/*
A AL_Texture is a local warped SDL_Texture, to support object-oriented programming. It provides a univeral construct/deconstruct API, plus automatically allocator.
Please note that texture should be used to store 2^ size graphic resources, otherwise the graphic memory is wasted. Make atlas before loading as actual textures, and render them with clip method.
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
    
    //直接在屏幕上渲染方法，左上角坐标系
    
    
    void DirectRender(float x, float y);
    
    void DirectRender(float x, float y, AL_Rectangle clipRect);
    
    void DirectRender(float x, float y, float width, float height);
    
    void DirectRender(float x, float y, float width, float height, AL_Rectangle clipRect);
    
    void DirectRender(AL_Rectangle targetRect);
    
    void DirectRender(AL_Rectangle targetRect, AL_Rectangle clipRect);
    
    
    
    
    //在摄像机上渲染
    void RenderToCamera(float x, float y,AL_Camera targetCamera);
    
    
    
    
    void AssignAlpha();
    
    void AssignWindow();
    
    
private:
    
    //被封装的实际SDL材质
    SDL_Texture *_pTargetTexture;
    SDL_Renderer *_pTargetRenderer;
    
};


void AL_Texture::DirectRender(float x, float y)
{
    
    
}



#endif /* AL_Texture_hpp */
