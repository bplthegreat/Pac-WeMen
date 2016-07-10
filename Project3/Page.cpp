#include "Page.h"

Page::Page()
{
	pageID = 0;
}

Page::~Page()
{
}
void Page::background_clear_render(int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(gRenderer, r, g, b, a);
	SDL_RenderClear(gRenderer);
}
