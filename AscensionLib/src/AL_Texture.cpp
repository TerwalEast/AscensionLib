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



void AscensionLib::AL_Texture::DirectRender()
{
    SDL_RenderCopy(AL_Window::_pRenderer, _pTargetTexture.get(), NULL, NULL);
}

void AscensionLib::AL_Texture::DirectRender(Rectangle targetRect, Rectangle clipRect)
{
    SDL_Rect clip = clipRect.getSDLRect();
    SDL_Rect target = targetRect.getSDLRect();
    
    SDL_RenderCopy(AL_Window::_pRenderer, _pTargetTexture.get(), &clip, &target);
    
    
}


bool AscensionLib::AL_Texture::Load(std::string path)
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
        SDL_FreeSurface(loadedSurface);
        return false;
    }

    SDL_FreeSurface( loadedSurface );
    SDL_SetTextureBlendMode(ptempSDL_Texture, SDL_BLENDMODE_BLEND);
    
    std::shared_ptr<SDL_Texture> ptempSmartTexture(ptempSDL_Texture,deleteSDL_Texture);
    _pTargetTexture = ptempSmartTexture;
    
    return true;
    
}

bool AscensionLib::AL_Texture::LoadWithMask(std::string sourceImagePath, std::string maskImagePath)
{
    
    SDL_Renderer* renderer = AL_Window::_pRenderer;
    
    //Load image at specified path
    SDL_Surface* loadedSourceSurface = IMG_Load( sourceImagePath.c_str() );
    if(!loadedSourceSurface)
    {
        std::cout << "读取遮罩源材质出现错误" << std::endl;
        return false;
    }
    SDL_Surface* loadedMaskSurface = IMG_Load( maskImagePath.c_str() );
    if(!loadedMaskSurface)
    {
        std::cout << "读取遮罩材质出现错误" << std::endl;
        SDL_FreeSurface(loadedSourceSurface);
        return false;
    }
    
    
    SDL_Texture* sourceTexture = SDL_CreateTextureFromSurface(renderer, loadedSourceSurface);
    SDL_Texture* maskTexture = SDL_CreateTextureFromSurface(renderer, loadedMaskSurface);
    
    SDL_FreeSurface(loadedSourceSurface);
    SDL_FreeSurface(loadedMaskSurface);
    
    int xMask,yMask,xSource,ySource;
    SDL_QueryTexture(sourceTexture, NULL, NULL, &xSource, &ySource);
    SDL_QueryTexture(maskTexture, NULL, NULL, &xMask, &yMask);
    
    if(xMask != xSource || yMask != ySource)
    {
        std::cout << "遮罩和目标的尺寸不符！" << std::endl;
        SDL_DestroyTexture(sourceTexture);
        SDL_DestroyTexture(maskTexture);
        return false;
    }
    
    SDL_Texture* result = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, xMask, yMask);
    SDL_SetRenderTarget(renderer, result);
    
    SDL_SetTextureBlendMode(result, SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(maskTexture, SDL_BLENDMODE_MOD);
    SDL_SetTextureBlendMode(sourceTexture, SDL_BLENDMODE_NONE);
    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, sourceTexture, NULL, NULL);
    SDL_RenderCopy(renderer, maskTexture, NULL, NULL);
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, 0,0,255,0);
    SDL_RenderClear(renderer);
    SDL_SetTextureBlendMode(result, SDL_BLENDMODE_BLEND);
    
    std::shared_ptr<SDL_Texture> ptempSmartTexture(result,deleteSDL_Texture);
    _pTargetTexture = ptempSmartTexture;
    
    SDL_DestroyTexture(maskTexture);
    SDL_DestroyTexture(sourceTexture);
    
    return true;
}


AscensionLib::AL_Texture::AL_Texture()
{
    
}

AscensionLib::AL_Texture::~AL_Texture()
{
    
}
