/*Includes the necessary Header file*/
#ifndef _INCLUDE
#define _INCLUDE
#include "Page.h"

SDL_Rect Clip;
Uint16 ticks = 0;

//Quit flag=false;
bool quit = false;

enum winner{
	PLAYER1=0,
	PLAYER2=1
};

winner Winner = PLAYER1;

//Define necessary Page objects
Page StartPage;
Page MenuPage;
//Page NamePage;
Page VsPage;
Page GamePage;
//Page PausePage;
Page WinPage;
Page HowtoPlayPage;
//Page HighScorepage;
Page Aboutpage;

enum ButtonID{
	PLAYGAMEID = 0,
	HOWTOPLAYID,
	HIGHSCOREID,
	ABOUTGAMEID,
	EXITID,
	//RESUMEID,
	//RESTARTID,
	//TOMENUID,
	BACKID
};

//Load the necessary music for game
void load_music(void);

/*Initialise windows*/
void Init_Windows(void);
void Init_sound(void);
void Quit_Windows(void);
void Init_JPGloading(void);
SDL_Renderer* ret_renderer(void);
void configure_picturesandbuttons(void);
void configure_page(int i);
void stop_music(void);
void set_clip(int x, int y, int w, int h);

//Setting up all needed pages foe display and sound when needed
void setup_startup_page(void);
void setup_menu_page(void);
void setup_name_page(void);
void setup_vs_page(void);
void setup_game_page(void);
void setup_pause_page(void);
void setup_score_page(void);
void setup_howtoplay_page(void);
void setup_highscore_page(void);
void setup_about_page(void);

#endif