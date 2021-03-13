//
//  AL_ResourceManager.cpp
//  AscensionLib
//
//  Created by shan on 2021/3/5.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_ResourceManager.hpp"





void AL_ResourceManager::ClearTextureMap()
{
    _textureMap.clear();
};

void AL_ResourceManager::ClearFromTextureMap(std::string id)
{
    _textureMap.find(id);
    
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
