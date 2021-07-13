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
#include <string>
#include "STG.hpp"
#include "AL_Texture.hpp"


inline std::string getBasePath()
{
    std::string *temp = new std::string(SDL_GetBasePath());
    return *temp;
}

namespace AscensionLib {
class AL_ResourceManager
{
    
public:
    
    static AL_ResourceManager& AL_GetResourceManager()
    {
        return _ResourceManager;
    }
    
    
    
    
    static void ClearTextureMap();
    static void ClearFromTextureMap(std::string id);
    
    
    
    
    /**
     *标准模式读取材质，直接读取现成的文件。
     *
     * \return 成功时返回材质对象的引用，失败时返回null
     */
    
    static AscensionLib::AL_Texture* LoadTexture(std::string filePath, std::string textureID);
    
    
    /**
     *根据读取材质时提供的材质ID，获取材质指针。
     *
     */
    
    static AscensionLib::AL_Texture* GetTextureByID(std::string textureID);
    
    /**
     *使用老模式读取材质，应付那些古老的、在主材质中没有Alpha通道而另外附带一张材质作为Alpha通道的材质。
     *SDL框架做不到这点，必须准备上OpenGL了。
     */
    static AscensionLib::AL_Texture* LoadTextureWithMask(std::string textureFilePath, std::string alphaFilePath, std::string textureID);
    
    
private:
    AL_ResourceManager()
    {
        _resourcePath = getBasePath();
    };
    ~AL_ResourceManager();
    AL_ResourceManager(const AL_ResourceManager& resourceManager) = delete;
    AL_ResourceManager& operator = (const AL_ResourceManager resourceManager) = delete;
    static std::map<std::string,AL_Texture> _textureMap;
    static AscensionLib::AL_ResourceManager _ResourceManager;
    static std::string _resourcePath;
};

}






#endif /* AL_ResourceManager_hpp */
