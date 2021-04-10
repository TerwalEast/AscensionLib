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

AL_Texture* AL_ResourceManager::GetTextureByID(std::string textureID)
{
    std::map<std::string, AL_Texture>::iterator it;
    
    it = _textureMap.find(textureID);
    
    if( it  == _textureMap.end())
    {
        return nullptr;
    }
    
    return &(it->second);
}

AL_ResourceManager::~AL_ResourceManager()
{
    _textureMap.clear();
    
}


AL_Texture* AL_ResourceManager::LoadTexture(std::string filePath, std::string textureID)
{
    
    std::map<std::string, AL_Texture>::iterator it;
    
    AL_Texture tempTexture;
    
    if( ! tempTexture.Load(filePath) )  //材质加载不成功时
    {
        return nullptr;
    }
    
    std::pair<std::map<std::string, AL_Texture>::iterator, bool> pair;
    
    pair = _textureMap.insert(std::pair<std::string, AL_Texture>(textureID, tempTexture));
    
    if(!pair.second) //插入失败，重复ID
    {
        return nullptr;
    }
    
    return &(pair.first->second);
}

AL_Texture* AL_ResourceManager::LoadtextureLegacy(std::string textureFilePath, std::string alphaFilePath, std::string textureID)
{
    
}

void AL_ResourceManager::ClearTextureMap()
{
    _textureMap.clear();
};

void AL_ResourceManager::ClearFromTextureMap(std::string id)
{
    if(_textureMap.erase(id) == 0) //代表没找到这个id对应的texture
    {
        cout << ": " << "删除失败" << endl;
        
        
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
