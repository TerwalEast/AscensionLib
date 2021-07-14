//
//  AL_Texture.hpp
//  AscensionLib
//
//  Created by shan on 2021/1/27.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef AL_Texture_hpp
#define AL_Texture_hpp

#include "STG.hpp"
#include "Util.hpp"


/*
A AL_Texture is a local warped SDL_Texture, to support object-oriented programming. It provides a univeral construct/deconstruct API, plus automatically allocator.
Please note that texture should be used to store 2^ size graphic resources, otherwise the graphic memory is wasted. Make atlas before loading as actual textures, and render them with clip method.
 */




namespace AscensionLib {
class AL_Camera;
class AL_Texture
{
public:
    
    static void deleteSDL_Texture(SDL_Texture* _pSDL_Texture)
    {
        SDL_DestroyTexture(_pSDL_Texture);
    }
    
    //构造
    AL_Texture();
    
    //析构
    ~AL_Texture();
    
    /**
     *从文件中读取材质。你可以用这个函数让一个材质对象重新读取另一个材质文件，但我不知道这会有什么后果。
     */
    bool Load(std::string path);
    
    /**
     *用遮罩模式读取材质。
     */
    bool LoadWithMask(std::string sourceImagePath,std::string maskImagePath);
    
    //-------------------------

    //-------------------------
    
    
    //整块材质对整个屏幕，直接渲染
    void DirectRender();

    
    //渲染材质中clipRect的部分，渲染到targetRect
    void DirectRender(Rectangle targetRect, Rectangle clipRect);
    
    
    //在摄像机上渲染,x/y为其中心坐标
    void RenderToCamera(float x, float y,AL_Camera targetCamera);
    
    void SetAlphaMode(uint alpha);
    
    SDL_Texture* GetSDLTexture()
    {
        return _pTargetTexture.get();
    }
    
private:
    
    //被封装的实际SDL材质
    //SDL_Texture *_pTargetTexture;
    std::shared_ptr<SDL_Texture> _pTargetTexture ;
    
};}









#endif /* AL_Texture_hpp */
