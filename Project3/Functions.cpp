#include"include.h"

void loadmusic()
{
	Music::ptr = Mix_LoadMUS("pacman_beginning.wav");
	Begin.setsound(Music::ptr);
	Music::ptr = Mix_LoadMUS("pacman_chomp.wav");
	Chomp.setsound(Music::ptr);
	Music::ptr = Mix_LoadMUS("pacman_eatfruit.wav");
	Eat.setsound(Music::ptr);
	Music::ptr = Mix_LoadMUS("pacman_death.wav");
	Death.setsound(Music::ptr);
	Music::ptr = Mix_LoadMUS("pacman_intermission.wav");
	Inter.setsound(Music::ptr);
	Music::ptr = Mix_LoadMUS("click.wav");
	Click.setsound(Music::ptr);
	Music::ptr = Mix_LoadMUS("hover.wav");
	Hover.setsound(Music::ptr);
	Music::ptr = Mix_LoadMUS("Naruto - The Rising Fighting Spirit.mp3");
	Naruto_fighting_spirit.setsound(Music::ptr);
	Music::ptr = Mix_LoadMUS("Beauty-motivational-music.mp3");
	background_music.setsound(Music::ptr);
}

SDL_Renderer* ret_renderer(void)
{
	return gRenderer;
}

void Init_sound(void)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error:", Mix_GetError());
	}
}

void Init_Windows(void)
{
	//Initialisation Flag
	Init_sound();
	loadmusic();
	Init_JPGloading();
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL cannot be initialised" << SDL_GetError << endl;
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Pacmen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window couldn't be started" << SDL_GetError << endl;
			success = false;
		}
		else
		{
			MainWindow = gWindow;
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cout << "Error in creating renderer" << SDL_GetError << endl;
				success = false;
			}
			else
			{
				MainRenderer = gRenderer;
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xff);
				SDL_RenderClear(gRenderer);
				SDL_RenderPresent(gRenderer);
			}
		}
	}
}


void Quit_Windows(void)
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;
	SDL_QUIT;
}

void Init_JPGloading(void)
{
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
	imgFlags = IMG_INIT_JPG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
}


void configure_picturesandbuttons(void)
{
	//Startup Page
	StartPage.picture[0].loadFromFile("startup_screen.jpg");
	StartPage.picture[1].loadFromFile("PressAnyKey.png");


	//Menu Page
	//Load Background;
	MenuPage.picture[0].loadFromFile("menu.jpg");
	//Load title
	MenuPage.picture[1].loadFromFile("title.png");
	MenuPage.button[PLAYGAMEID].setButton(550, 200, 150, 50, PLAYGAMEID);
	MenuPage.button[HOWTOPLAYID].setButton(550, 275, 150, 50, HOWTOPLAYID);
	//MenuPage.button[HIGHSCOREID].setButton(550, 350, 150, 50, HIGHSCOREID);
	MenuPage.button[ABOUTGAMEID].setButton(550, 350, 150, 50, ABOUTGAMEID);
	MenuPage.button[EXITID].setButton(100, 400, 150, 50, EXITID);
	//Load Button Image
	MenuPage.button[PLAYGAMEID].Button_Texture.loadFromFile("play.png");
	MenuPage.button[HOWTOPLAYID].Button_Texture.loadFromFile("howtoplay.png");
	//MenuPage.button[HIGHSCOREID].Button_Texture.loadFromFile("highscore.png");
	MenuPage.button[ABOUTGAMEID].Button_Texture.loadFromFile("about.png");
	MenuPage.button[EXITID].Button_Texture.loadFromFile("exit.png");

	//Pause Page
	//PausePage.button[RESUMEID-5].setButton(50, SCREEN_HEIGHT / 2 - 50, 100, 100, RESUMEID);
	//PausePage.button[RESTARTID - 5].setButton(150, SCREEN_HEIGHT / 2 - 50, 100, 100, RESTARTID);
	//PausePage.button[TOMENUID - 5].setButton(250, SCREEN_HEIGHT / 2 - 50, 100, 100, TOMENUID);
	//PausePage.button[EXITID - 1].setButton(350, SCREEN_HEIGHT / 2 - 50, 100, 100, EXITID);

	//Load Image of Vs page
	VsPage.picture[0].loadFromFile("vs.png");
	VsPage.picture[1].loadFromFile("loading.png");
	VsPage.picture[2].loadFromFile("player_1.png");
	VsPage.picture[3].loadFromFile("player_2.png");

	//Load Image and button for About page
	Aboutpage.picture[0].loadFromFile("about_page.png");
	Aboutpage.button[0].setButton(625, (SCREEN_HEIGHT - 50) / 2, 150, 50, BACKID);
	Aboutpage.button[0].Button_Texture.loadFromFile("back.png");

	//For Win Page
	WinPage.picture[0].loadFromFile("player1_wins.png");
	WinPage.picture[1].loadFromFile("player2_wins.png");
	
	//For Howtoplay page
	//Load Image and button for About page
	HowtoPlayPage.picture[0].loadFromFile("Howtoplay_page.png");
	HowtoPlayPage.button[0].setButton(625, (SCREEN_HEIGHT - 50) / 2, 150, 50, BACKID);
	HowtoPlayPage.button[0].Button_Texture.loadFromFile("back.png");
}

void stop_music(void)
{

	
	Begin.Stop();
	Chomp.Stop();
	Eat.Stop();
	Death.Stop();
	Inter.Stop();
	Click.Stop();
	Hover.Stop();
	Naruto_fighting_spirit.Stop();
}


void setup_startup_page(void)
{
	Page::background_clear_render(0, 0, 0, 0xff);

	//Render startup_screen.png
	set_clip(0, 0, StartPage.picture[0].getWidth(), StartPage.picture[0].getHeight());
	StartPage.picture[0].render(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &Clip, 0, NULL, SDL_FLIP_NONE);

	if (!(e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN))
	{
		if ((SDL_GetTicks() / 500) % 2 == 0)
		{
			set_clip(0, 0, StartPage.picture[1].getWidth(), StartPage.picture[1].getHeight());
			StartPage.picture[1].render((SCREEN_WIDTH - 600) / 2, SCREEN_HEIGHT - 150, 600, 250, &Clip, 0, NULL, SDL_FLIP_NONE);
		}
	}
	if (Mix_PlayingMusic() == 0)
		Begin.Play();
	if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
	{
		current_page = MENU_PAGE;
		Begin.Stop();
	}

}
void setup_menu_page(void)
{
	Page::background_clear_render(0, 0, 0, 0xff);
	
	set_clip( 0, 0, MenuPage.picture[0].getWidth(), MenuPage.picture[0].getHeight() );
	MenuPage.picture[0].render(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &Clip, 0, NULL, SDL_FLIP_NONE);

	set_clip( 0, 0, MenuPage.picture[1].getWidth(), MenuPage.picture[1].getHeight() );
	MenuPage.picture[1].render(0, 0, SCREEN_WIDTH, 150, &Clip, 0, NULL, SDL_FLIP_NONE);
	//Render all the buttons of the page
	MenuPage.button[PLAYGAMEID].Button_Texture.render(MenuPage.button[PLAYGAMEID].mPosition.x, MenuPage.button[PLAYGAMEID].mPosition.y, MenuPage.button[PLAYGAMEID].Button_Width, MenuPage.button[PLAYGAMEID].Button_Height, NULL, 0, NULL, SDL_FLIP_NONE);
	MenuPage.button[HOWTOPLAYID].Button_Texture.render(MenuPage.button[HOWTOPLAYID].mPosition.x, MenuPage.button[HOWTOPLAYID].mPosition.y, MenuPage.button[HOWTOPLAYID].Button_Width, MenuPage.button[HOWTOPLAYID].Button_Height, NULL, 0, NULL, SDL_FLIP_NONE);
	//MenuPage.button[HIGHSCOREID].Button_Texture.render(MenuPage.button[HIGHSCOREID].mPosition.x, MenuPage.button[HIGHSCOREID].mPosition.y, MenuPage.button[HIGHSCOREID].Button_Width, MenuPage.button[HIGHSCOREID].Button_Height, NULL, 0, NULL, SDL_FLIP_NONE);
	MenuPage.button[ABOUTGAMEID].Button_Texture.render(MenuPage.button[ABOUTGAMEID].mPosition.x, MenuPage.button[ABOUTGAMEID].mPosition.y, MenuPage.button[ABOUTGAMEID].Button_Width, MenuPage.button[ABOUTGAMEID].Button_Height, NULL, 0, NULL, SDL_FLIP_NONE);
	MenuPage.button[EXITID].Button_Texture.render(MenuPage.button[EXITID].mPosition.x, MenuPage.button[EXITID].mPosition.y, MenuPage.button[EXITID].Button_Width, MenuPage.button[EXITID].Button_Height, NULL, 0, NULL, SDL_FLIP_NONE);

	//Handle Button Events
	if (MenuPage.button[PLAYGAMEID].HandleStatus(&e)) 
		current_page = VS_PAGE;
	if (MenuPage.button[HOWTOPLAYID].HandleStatus(&e)) 
		current_page = HOW_TO_PLAY_PAGE;
	//if (MenuPage.button[HIGHSCOREID].HandleStatus(&e)) 
		//current_page = HIGH_SCORE_PAGE;
	if (MenuPage.button[ABOUTGAMEID].HandleStatus(&e)) 
		current_page = ABOUT_PAGE;
	if (MenuPage.button[EXITID].HandleStatus(&e))
	{
		Quit_Windows();
		quit = true;
	}
}
void setup_name_page(void)
{
	
	
}
void setup_vs_page(void)
{
	Page::background_clear_render(0, 0, 0, 0xff);

	set_clip(0, 0, VsPage.picture[0].getWidth(), VsPage.picture[0].getHeight());//render background image
	VsPage.picture[0].render(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &Clip, 0, NULL, SDL_FLIP_NONE);

	set_clip(0, 0, VsPage.picture[2].getWidth(), VsPage.picture[2].getHeight());//render Player1 name
	VsPage.picture[2].render(20, 100, VsPage.picture[2].getWidth()*0.6, VsPage.picture[2].getHeight()*0.6, &Clip, 0, NULL, SDL_FLIP_NONE);

	set_clip(0, 0, VsPage.picture[3].getWidth(), VsPage.picture[3].getHeight());//render Player2 name
	VsPage.picture[3].render(SCREEN_WIDTH - 285, SCREEN_HEIGHT - 200, VsPage.picture[3].getWidth()*0.6, VsPage.picture[3].getHeight()*0.6, &Clip, 0, NULL, SDL_FLIP_NONE);
	
	if (!(e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN))
	{
		if ((SDL_GetTicks() / 500) % 2 == 0)
		{
			set_clip(0, 0, VsPage.picture[1].getWidth(), VsPage.picture[1].getHeight());//render loading image
			VsPage.picture[1].render((SCREEN_WIDTH - VsPage.picture[1].getWidth()), SCREEN_HEIGHT - VsPage.picture[1].getHeight(), VsPage.picture[1].getWidth(), VsPage.picture[1].getHeight(), &Clip, 0, NULL, SDL_FLIP_NONE);
		}
	}
	


	static bool i = true;//bool to know whether it has been rendered from another page or same page
	if (i == false)
	{
		if (SDL_GetTicks() - ticks > 13000)//time of olaying background music;
		{
			current_page = GAME_PAGE;
			ticks = 0;
			i = true;
			Naruto_fighting_spirit.Stop();
		}
	}
	else
	{
		ticks = SDL_GetTicks();
		i = false;
		Naruto_fighting_spirit.Play();
	}
}
void setup_pause_page(void)
{

}
void setup_win_page(void)
{
	Page::background_clear_render(0, 0, 0, 0xff);

	set_clip(0, 0, WinPage.picture[0].getWidth(), WinPage.picture[0].getHeight());

	if (Winner==PLAYER1)
	{
		
		WinPage.picture[0].render(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &Clip, 0, NULL, SDL_FLIP_NONE);
	}
	else
	{
		WinPage.picture[1].render(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &Clip, 0, NULL, SDL_FLIP_NONE);
	}
	current_page = START_PAGE;
}
void setup_howtoplay_page(void)
{
	Page::background_clear_render(0, 0, 0, 0xff);

	set_clip(0, 0, HowtoPlayPage.picture[0].getWidth(), HowtoPlayPage.picture[0].getHeight());
	HowtoPlayPage.picture[0].render(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &Clip, 0, NULL, SDL_FLIP_NONE);//About Text Picture Rendering

	HowtoPlayPage.button[0].Button_Texture.render(HowtoPlayPage.button[0].mPosition.x, HowtoPlayPage.button[0].mPosition.y, HowtoPlayPage.button[0].Button_Width, HowtoPlayPage.button[0].Button_Height, NULL, 0, NULL, SDL_FLIP_NONE);
	static bool first_time_ = true;
	if (first_time_)
	{
		first_time_ = false;
		background_music.Play();
	}
	//Handle Back button event
	//Handle Button Events
	if (HowtoPlayPage.button[0].HandleStatus(&e))
	{
		background_music.Stop();
		first_time_ = true;
		current_page = MENU_PAGE;
	}

}
void setup_highscore_page(void)
{

}
void setup_about_page(void)
{
	Page::background_clear_render(0, 0, 0, 0xff);

	set_clip(0, 0, Aboutpage.picture[0].getWidth(), Aboutpage.picture[0].getHeight());
	Aboutpage.picture[0].render(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &Clip, 0, NULL, SDL_FLIP_NONE);//About Text Picture Rendering

	Aboutpage.button[0].Button_Texture.render(Aboutpage.button[0].mPosition.x, Aboutpage.button[0].mPosition.y, Aboutpage.button[0].Button_Width, Aboutpage.button[0].Button_Height, NULL, 0, NULL, SDL_FLIP_NONE);
	static bool first_time = true;
	if (first_time)
	{
		first_time = false;
		background_music.Play();
	}
	//Handle Back button event
	//Handle Button Events
	if (Aboutpage.button[0].HandleStatus(&e))
	{
		background_music.Stop();
		first_time = true;
		current_page = MENU_PAGE;
	}
}
void setup_game_page(void)
{
	int x;
	x=FunctionIdentfiers::EntryLoop();
	if (x == 1)
	{
		Winner = PLAYER1;
	}
	else if (x == 2)
	{
		Winner = PLAYER2;
	}
	if (x == 0)
		current_page = MENU_PAGE;
	else
		current_page = WIN_PAGE;
}


//Configure picture and buttons of pages
void configure_page(int i)
{
	switch (i)
	{
		case START_PAGE://configuring starting page
			setup_startup_page();
		break;

		case MENU_PAGE:
			setup_menu_page();
			break;
		case HOW_TO_PLAY_PAGE:
			setup_howtoplay_page();
			break;
		//case HIGH_SCORE_PAGE:
			//break;
		//case NAME_PAGE:
				//break;
		case VS_PAGE:
			setup_vs_page();
				break;
		case GAME_PAGE:
			setup_game_page();
				break;
		//case PAUSE_PAGE:
				//break;
		case WIN_PAGE:
			setup_win_page();
				break;
		case ABOUT_PAGE:
			setup_about_page();
				break;
	}
}

void set_clip(int x, int y, int w, int h)
{
	Clip.x = x;
	Clip.y = y;
	Clip.w = w;
	Clip.h = h;
}