#pragma once
#include "include.h"
#include"Ltexture.h"
//Button constants

enum LButtonFunction
{
	BUTTON_MOUSE_OUT = 0,
	BUTTON_MOUSE_OVER_MOTION = 1,
	BUTTON_MOUSE_DOWN = 2,
	BUTTON_MOUSE_UP = 3,
	BUTTON_TOTAL = 4
};


class LButton
{
private:
	//Top left position
	SDL_Point mPosition;

	Uint8 BUTTON_WIDTH ;
	Uint8 BUTTON_HEIGHT ;


	//Currently used global sprite
	LButtonFunction status;
	
public:
	bool new_hover_status;
	bool new_click_status;
	LButton();
	LButton(int X, int Y, int W, int H);
	~LButton();

	//Sets top left position
	void setPosition(int x, int y);
	
	void Draw_Button(int R, int G, int B, int A);

	//Handles mouse event
	void handleEvent(SDL_Event* e);

	/*Return the current status of the button*/
	LButtonFunction return_status(void);
	bool return_new_hover_status(void);

};

