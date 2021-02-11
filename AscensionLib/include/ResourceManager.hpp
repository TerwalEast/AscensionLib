//
//  ResourceManager.hpp
//  STG_Demo
//
//  Created by shan on 2021/1/21.
//  Copyright © 2021 Terwal. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <stdio.h>
#include "STG.hpp"
#include "Game.hpp"

#ifdef __APPLE__
#include <CoreFoundation/CoreFoundation.h>
#include "ResourcePath.hpp"
#endif

void Game::_initRelativePaths() {
// ----------------------------------------------------------------------------
// This makes relative paths work in C++ in Xcode by changing directory to the Resources folder inside the .app bundle
#ifdef __APPLE__
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
    char path[PATH_MAX];
    if (!CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX))
    {
        // error!
    }
    CFRelease(resourcesURL);

    chdir(path);
    #endif
    // ---------------------------------------------------------------------------    -
/*
 TODO: Windows版本的管理器
 
 
    
*/
    
}







#endif /* ResourceManager_hpp */
