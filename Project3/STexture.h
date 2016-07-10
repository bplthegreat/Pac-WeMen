#pragma once

#include "PlayMusic.h"

SDL_Window* gWindow=NULL;
SDL_Renderer* gRenderer=NULL;

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;


PlayMusic Begin;
PlayMusic Chomp;
PlayMusic Eat;
PlayMusic Death;
PlayMusic Inter;
PlayMusic Click;
PlayMusic Hover;
PlayMusic Naruto_fighting_spirit;
PlayMusic background_music;

class STexture
{
public:private:
	//The actual hardware texture
	SDL_Texture* mTexture;
	//SDL_Rect Clip;

	//Image dimensions
	int mWidth;
	int mHeight;
	bool set;
public:
	//Initializes variables
	STexture();

	//Deallocates memory
	~STexture();

	//Loads image at specified path
	bool loadFromFile(std::string path);

#ifdef _SDL_TTF_H
	bool STexture::loadFromRenderedText(std::string textureText, SDL_Color textColor);
#endif

	void set_clip(int x, int y, int w, int h);
	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(int x, int y, int w, int h, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	
	//Gets image dimensions
	int getWidth();
	int getHeight();
	bool get_setstatus();

};

