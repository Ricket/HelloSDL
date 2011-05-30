//
//  main.cpp
//  HelloSDL
//
//  Created by Ricky Carter on 5/30/11.
//  Copyright 2011 Student. All rights reserved.
//

#include <stdlib.h>
#include <SDL/SDL.h>
#include "main.h"

#define WIDTH 640
#define HEIGHT 480
#define WINDOW_TITLE "Window Title"

SDL_Surface *screen;

int SDL_main (int argc, char **argv) {
    // Initialize
    SDL_Init(SDL_INIT_VIDEO);
    
    // Enable double-buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    // Create a OpenGL window
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, SDL_OPENGL | 
                              SDL_RESIZABLE);
    if(!screen) 
    {
        printf("Couldn't set %dx%d GL video mode: %s\n", WIDTH,
               HEIGHT, SDL_GetError());
        SDL_Quit();
        exit(2);
    }
    SDL_WM_SetCaption(WINDOW_TITLE, WINDOW_TITLE); 
    
    
    
    bool done = false;
    while(!done) 
    {
        SDL_Event event;
        // Rotates the triangle (this could be replaced with custom
        // processing code)
        // animate();
        
        // Respond to any events that occur
        while(SDL_PollEvent(&event))
        {
            switch(event.type) 
            {
                case SDL_VIDEORESIZE:
                    screen = SDL_SetVideoMode(event.resize.w, 
                                              event.resize.h, 0,
                                              SDL_OPENGL | SDL_RESIZABLE);
                    if(screen)
                    {
                        // reshape(screen->w, screen->h);
                    } 
                    else 
                    {
                        ; // Oops, we couldn't resize for some reason. 
                        // This should never happen
                    }
                    break;
                    
                case SDL_QUIT:
                    done = true;
                    break;		
                    
                    // ## INSERT CODE TO HANDLE ANY OTHER EVENTS HERE ##
            }
        }
        
        // Check for escape
        Uint8 *keys = SDL_GetKeyState(NULL);
        if( keys[SDLK_ESCAPE] ) {
            done = true;
        }
        
        // Draw the screen
        // render();
    }
    
    
    
    SDL_Quit();
    return 0;
}