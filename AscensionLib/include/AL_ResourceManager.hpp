//
//  AL_ResourceManager.hpp
//  AscensionLib
//
//  Created by shan on 2021/3/5.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef AL_ResourceManager_hpp
#define AL_ResourceManager_hpp

#include <stdio.h>
#include "STG.hpp"
#include "AL_Texture.hpp"













class AL_ResourceManager
{
    
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
    
    static std::map<std::string,AL_Texture> _textureMap;
    
    
    static AL_ResourceManager _ResourceManager;
    
    
};




#endif /* AL_ResourceManager_hpp */
