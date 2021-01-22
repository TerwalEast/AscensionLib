//
//  gameObject.hpp
//  STG_Demo
//
//  Created by shan on 2021/1/18.
//  Copyright © 2021 Terwal. All rights reserved.
//

#ifndef gameObject_hpp
#define gameObject_hpp

#include "STG.hpp"

class GameObjectBase
{
public:
    GameObjectBase();
    virtual ~GameObjectBase();
    virtual void Update(uint64_t elapsedTimeInMS);
    
    
private:
    
    
};


#endif /* gameObject_hpp */
