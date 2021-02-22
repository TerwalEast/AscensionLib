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
/*
A AL_Texture is a local warped SDL_Texture, to support object-oriented programming. It provides a univeral construct/deconstruct API, plus automatically allocator.
Please note that texture should be used to store 2^ size graphic resources, otherwise the graphic memory is wasted. Make atlas before loading as actual textures, and render them using clip() method.
 */




class AL_Texture
{
public:
    
    SDL_Texture *_targetTexture;
    SDL_Renderer *_targetRenderer;
    
    AL_Texture();
    ~AL_Texture();
    
    void Load(std::string path);
    void Destroy();
    
    
    
    
    
};




#endif /* AL_Texture_hpp */
