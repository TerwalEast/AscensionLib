//
//  AL_ResourceManager.cpp
//  AscensionLib
//
//  Created by shan on 2021/3/5.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_ResourceManager.hpp"
#include "../include/AL_Window.hpp"


using namespace AscensionLib;




std::map<std::string,AL_Texture> AL_ResourceManager::_textureMap;
std::string AL_ResourceManager::_resourcePath;

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

[[nodiscard]]AL_Texture* AL_ResourceManager::LoadTexture(std::string filePath, std::string textureID)
{
    
    std::map<std::string, AL_Texture>::iterator it;
    AL_Texture tempTexture;
    if( ! tempTexture.Load( _resourcePath + filePath) )  //材质加载不成功时
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

AL_Texture* AL_ResourceManager::LoadTextureWithMask(std::string textureFilePath, std::string alphaFilePath, std::string textureID)
{
    std::map<std::string, AL_Texture>::iterator it;
    AL_Texture tempTexture;
    if( ! tempTexture.LoadWithMask( _resourcePath + textureFilePath , _resourcePath + alphaFilePath) )  //材质加载不成功时
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


void AL_ResourceManager::ClearTextureMap()
{
    _textureMap.clear();
};

void AL_ResourceManager::ClearFromTextureMap(std::string id)
{
    if(_textureMap.erase(id) == 0) //代表没找到这个id对应的texture
    {
        std::cout << ": " << "删除失败" << std::endl;
    }
    else //找到并删除了这个id对应的texture
    {
    }
}
