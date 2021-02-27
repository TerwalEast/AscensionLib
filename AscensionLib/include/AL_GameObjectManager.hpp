//
//  gameObjectManager.hpp
//  STG_Demo
//
//  Created by shan on 2021/1/18.
//  Copyright © 2021 Terwal. All rights reserved.
//

#ifndef gameObjectManager_hpp
#define gameObjectManager_hpp

#include "STG.hpp"
#include <vector>
#include "AL_GameObjectBase.hpp"

using namespace std;

class AL_GameObjectManager
{
    
public:
    
    AL_GameObjectManager();
    ~AL_GameObjectManager();
    
    
    vector<AL_GameObjectBase> _objects;
    
private:
    
    
    void handleInput();
    void handle();
    
    
    
    
};

#endif /* gameObjectManager_hpp */
