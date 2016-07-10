#include "LButton.h"


LButton::LButton()
{
	gRenderer = ret_renderer();
	mPosition.x = 0;
	mPosition.y = 0;
	status = BUTTON_MOUSE_OUT;

}

LButton::LButton(int X, int Y, int W, int H) 
{
	gRenderer = ret_renderer();
	mPosition.x = X;
	mPosition.y = Y;
	BUTTON_WIDTH = W;
	BUTTON_HEIGHT = H;
	status = BUTTON_MOUSE_OUT;
	new_hover_status = true;
	new_click_status = true;
}


LButton::~LButton()
{

}

void LButton::Draw_Button(int R, int G, int B, int A)
{
	//cout << gRenderer << endl;
	SDL_SetRenderDrawColor(gRenderer, R, G, B, A);
	SDL_Rect button;
	button.x = mPosition.x;
	button.y = mPosition.y;
	button.w = BUTTON_WIDTH;
	button.h = BUTTON_HEIGHT;
	SDL_RenderFillRect(gRenderer, &button);
	new_hover_status = true;
	new_click_status = true;
}

void LButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::handleEvent(SDL_Event* e)
{
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < mPosition.x)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if (x > mPosition.x + BUTTON_WIDTH)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < mPosition.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > mPosition.y + BUTTON_HEIGHT)
		{
			inside = false;
		}

		//Mouse is outside button
		if (!inside)
		{
			status = BUTTON_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				status = BUTTON_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				status = BUTTON_MOUSE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				status = BUTTON_MOUSE_UP;
				break;
			}
		}
	}
}

LButtonFunction LButton::return_status(void)
{
	return status;
}
bool LButton::return_new_hover_status(void)
{
	return new_hover_status;
}



