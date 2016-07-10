/*Includes the necessary Header file*/
#ifndef _INCLUDE
#define _INCLUDE

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <SDL_render.h>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

/*Initialise the global variables required*/

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Globally used font
TTF_Font *gFont = NULL;
#endif;