#ifndef PLAYMUSIC_H
#define PLAYMUSIC_H
//Using SDL, SDL_image, SDL_ttf, SDL_mixer, standard IO, math, and strings

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <SDL_render.h>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <SDL_mixer.h>
#include"functions.h"
#include"ClassTexture.h"
#include"ClassMovingTexture.h"
using namespace FunctionIdentfiers;
using namespace Global;

//Declare pointer to load Music
namespace Music
{
	Mix_Music *ptr;
}

class PlayMusic
{
    public:
        PlayMusic();
        PlayMusic(Mix_Music *);
		void setsound(Mix_Music* p);
        virtual ~PlayMusic();
        void Play();
		void Play_ntimes(int i);
        void Stop();
    protected:
    private:
        Mix_Music *sound;
};
#endif // PLAYMUSIC_H
