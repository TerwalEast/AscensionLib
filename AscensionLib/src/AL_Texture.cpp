//
//  AL_Texture.cpp
//  AscensionLib
//
//  Created by shan on 2021/1/27.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_Texture.hpp"




void AL_Texture :: Load(std::string path)
{
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
        return;
    }
    //Create texture from surface pixels
    //_targetTexture = SDL_CreateTextureFromSurface( loadedSurface );
    if( _targetTexture == NULL )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    SDL_FreeSurface( loadedSurface );
    
    
}

void AL_Texture :: Destroy()
{
    SDL_DestroyTexture(_targetTexture);
    
    
}

AL_Texture :: ~AL_Texture()
{
    Destroy();
}
