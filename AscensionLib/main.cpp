//
//  main.cpp
//  STG_Demo
//
//  Created by shan on 2021/1/17.
//  Copyright © 2021 Terwal. All rights reserved.
//

#include <iostream>


#include <string>
#include "GameManager.hpp"

const int SCREEN_WIDTH = 612;
const int SCREEN_HEIGHT = 612;



//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* gSplashTexture = NULL;
SDL_Texture* gBoardTexture = NULL;
SDL_Texture* gPieceTexture = NULL;

//时钟
AL_GameClock *localClock = NULL;

//游戏本体
GameManager *gGameManager = NULL;



int main( int argc, char* args[] )
{

    
    //游戏模块初始化
    localClock = new AL_GameClock();
    
    gGameManager = new GameManager();
    gGameManager->InitGame();
    
    
    
    
    
    
    
}







/*
bool init()
{
    //Initialization flag
    bool success = true;

    //初始化时钟
    localClock = new GameClock();


    //初始化 SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia(SDL_Texture *targetTexture,std::string path)
{
    //Loading success flag
    bool success = true;

    //Load PNG texture
    targetTexture = loadTexture(path);
    if( targetTexture == NULL )
    {
        printf( "Failed to load texture image!\n" );
        success = false;
    }

    SDL_SetTextureBlendMode(targetTexture, SDL_BLENDMODE_BLEND);

    return success;
}

void close()
{
    //Free loaded image
    SDL_DestroyTexture( gBoardTexture );
    gBoardTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

int main( int argc, char* args[] )
{

    srand((unsigned)time(NULL));

    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia(gSplashTexture,"/Users/shan/Desktop/AscensionLib/AscensionLib/Resources/EoSD/th06logo.jpg")
           || !loadMedia(gBoardTexture,"/Users/shan/Desktop/AscensionLib/AscensionLib/Resources/Aeroplane/unnamed.png"))
        {
            printf( "Failed to load media!\n" );
            close();
            exit(0);
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            int alpha;
            double timeStack = 0;

            localClock->UpdateTime();
            localClock->GetElapsedTime();

            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                }

                //Clear screen
                SDL_RenderClear( gRenderer );

                SDL_Rect fillRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
                SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
                SDL_RenderFillRect( gRenderer, &fillRect );

                localClock->UpdateTime();
                timeStack += localClock->GetElapsedTime();


                std::cout << "time: " << timeStack << std::endl;

                alpha = floor(timeStack / 3 * 255);


                SDL_SetTextureAlphaMod(gSplashTexture, alpha);

                std::cout << alpha << std::endl;

                //Render texture to screen
                SDL_RenderCopy( gRenderer, gSplashTexture, NULL, NULL );

                //Update screen
                SDL_RenderPresent( gRenderer );

                if(timeStack >= 3 )break;




            }

            timeStack = 0;
            localClock->UpdateTime();
            localClock->GetElapsedTime();
            while(timeStack <= 1)
            {

                localClock->UpdateTime();
                localClock->GetElapsedTime();
                timeStack += localClock->GetElapsedTime();


            }

            //淡出
            timeStack = 0;
            localClock->UpdateTime();
            localClock->GetElapsedTime();

            while(timeStack <= 3)
            {
                SDL_RenderClear( gRenderer );
                localClock->UpdateTime();
                timeStack += localClock->GetElapsedTime();
                alpha = floor(timeStack / 3 * 255);


                SDL_SetTextureAlphaMod(gSplashTexture, alpha);

                std::cout << alpha << std::endl;

                //Render texture to screen
                SDL_RenderCopy( gRenderer, gSplashTexture, NULL, NULL );

                //Update screen
                SDL_RenderPresent( gRenderer );

            }






        }
    }

    //Free resources and close SDL
    close();

    return 0;
}
 
 */
