//
//  AL_Texture.cpp
//  AscensionLib
//
//  Created by shan on 2021/1/27.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_Texture.hpp"
#include "../include/AL_Window.hpp"
#include "../include/AL_Camera.hpp"


void AL_Texture::DirectRender()
{
    SDL_RenderCopy(AL_Window::_pRenderer, _pTargetTexture.get(), NULL, NULL);
}


bool AL_Texture::Load(std::string path)
{
    
    SDL_Texture* ptempSDL_Texture;
    
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        return false;
    }
    //Create texture from surface pixels
    ptempSDL_Texture = SDL_CreateTextureFromSurface(AL_Window::_pRenderer, loadedSurface);
    if( ptempSDL_Texture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        return false;
    }

    SDL_FreeSurface( loadedSurface );
    SDL_SetTextureBlendMode(ptempSDL_Texture, SDL_BLENDMODE_NONE);
    
    std::shared_ptr<SDL_Texture> ptempSmartTexture(ptempSDL_Texture,deleteSDL_Texture);
    _pTargetTexture = ptempSmartTexture;
    
    return true;
    
}



AL_Texture::AL_Texture()
{
    
}

AL_Texture::~AL_Texture()
{
    
}
