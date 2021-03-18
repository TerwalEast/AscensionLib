//
//  AL_ResourceManager.cpp
//  AscensionLib
//
//  Created by shan on 2021/3/5.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_ResourceManager.hpp"
#include "../include/AL_Window.hpp"

using namespace std;

std::map<std::string,AL_Texture> AL_ResourceManager::_textureMap;


bool AL_ResourceManager::LoadTexture(std::string filePath, std::string textureID)
{
    AL_Texture tempTexture;
    
    
    SDL_Surface *pTempSurface = IMG_Load(filePath.c_str());
    if(pTempSurface == nullptr)
    {
        return false;
    }
    
    SDL_Texture *pTempTexture = SDL_CreateTextureFromSurface(AL_Window::GetSDLRenderer(), pTempSurface);
        
    
    
    
    return true;
}

void AL_ResourceManager::ClearTextureMap()
{
    _textureMap.clear();
};

void AL_ResourceManager::ClearFromTextureMap(std::string id)
{
    if(_textureMap.erase(id) == 0) //代表没找到这个id对应的texture
    {
        cout << GetTimeString() << ": " << "删除失败" << endl;
        
        
    }
    else //找到并删除了这个id对应的texture
    {
        
        
        
    }
    
    
    
    
}


/*
 public:
     
     static AL_ResourceManager& AL_GetResourceManager()
     {
         return _ResourceManager;
     }
     
     
     static void ClearTextureMap();
     static void ClearFromTextureMap(std::string id);
     static bool LoadTexture(std::string filePath, std::string textureID);
     
     
     
 private:
     
     AL_ResourceManager(){};
     ~AL_ResourceManager(){};
     AL_ResourceManager(const AL_ResourceManager& resourceManager) = delete;
     AL_ResourceManager& operator = (const AL_ResourceManager resourceManager) = delete;
     
     std::map<std::string,AL_Texture> _textureMap;
     
     
     static AL_ResourceManager _ResourceManager;
     
 
 
 */
