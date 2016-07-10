#include "include.h"


int main(int argc, char* args[])
{

	Init_Windows();

	current_page = START_PAGE;


	//Configure necessary buttons in necessary place, position and ID;
	configure_picturesandbuttons();
	stop_music();
	


	while (!quit)
	{

		while (SDL_PollEvent(&e) != 0)
		SDL_PollEvent(&e);
		{
			if (e.type == SDL_QUIT)
				quit = true;
			Page::background_clear_render(0, 0, 0, 0xff);
			cout<<"Current page= " << current_page << endl;
			configure_page(current_page);
		}
		SDL_RenderPresent(gRenderer);
	}
	Quit_Windows();

	return 0;
}