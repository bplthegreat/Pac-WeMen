#pragma once
#include "STexture.h"
//Button constants
SDL_Event e;

enum LButtonFunction
{
	BUTTON_MOUSE_OUT = 0,
	BUTTON_MOUSE_OVER_MOTION = 1,
	BUTTON_MOUSE_DOWN = 2,
	BUTTON_MOUSE_UP = 3,
	BUTTON_TOTAL = 4
};



class SButton
{
private:
public:
	//Top left position
	SDL_Point mPosition;

	Uint8 Button_Width;
	Uint8 Button_Height;


	//Currently used global sprite
	LButtonFunction status;
	STexture Button_Texture;
	Uint8 ID;

public:
	bool new_hover_status;
	bool new_click_status;
	SButton();
	SButton(int X, int Y, int W, int H,Uint8 id);
	~SButton();

	//Sets top left position
	void setButton(int x, int y,int w,int h,Uint8 id);

	void Draw_Button(int R, int G, int B, int A);

	//Handles mouse event
	void getStatus(SDL_Event* f);

	bool HandleStatus(SDL_Event* g);

	/*Return the current status of the button*/
	LButtonFunction return_status(void);
	bool return_new_hover_status(void);


};


