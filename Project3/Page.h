#pragma once
#include"SButton.h"

enum screen{
	START_PAGE = 0,
	MENU_PAGE = 1,
	//NAME_PAGE = 2,
	VS_PAGE = 3,
	GAME_PAGE = 4,
	//PAUSE_PAGE = 5,
	WIN_PAGE = 6,
	HOW_TO_PLAY_PAGE = 7,
	//HIGH_SCORE_PAGE = 8,
	ABOUT_PAGE = 9,
	TOTAL_PAGE = 10
};
enum screen current_page;

class Page
{
	public:
	SButton button[5];
	STexture picture[5];
	Uint8 pageID;
public:
	Page();
	~Page();
	//Renders necessay background color
	static void background_clear_render(int r, int g, int b, int a);
};

