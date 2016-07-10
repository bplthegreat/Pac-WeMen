#include "SButton.h"



SButton::SButton()
{
	mPosition.x = 0;
	mPosition.y = 0;
	ID = 0;
	status = BUTTON_MOUSE_OUT;
	new_hover_status = true;
	new_click_status = true;
	//load necessary music
	
}

SButton::SButton(int X, int Y, int W, int H,Uint8 id)
{
	mPosition.x = X;
	mPosition.y = Y;
	Button_Width = W;
	Button_Height = H;
	ID = id;
	status = BUTTON_MOUSE_OUT;
	new_hover_status = true;
	new_click_status = true;
}


SButton::~SButton()
{

}

void SButton::Draw_Button(int R, int G, int B, int A)
{
	//cout << gRenderer << endl;
	SDL_SetRenderDrawColor(gRenderer, R, G, B, A);
	SDL_Rect button;
	button.x = mPosition.x;
	button.y = mPosition.y;
	button.w = Button_Width;
	button.h = Button_Height;
	SDL_RenderFillRect(gRenderer, &button);
	new_hover_status = true;
	new_click_status = true;
}


void SButton::setButton(int x, int y, int w, int h, Uint8 id)
{
	mPosition.x = x;
	mPosition.y = y;
	Button_Width = w;
	Button_Height = h;
	ID = id;

}

void SButton::getStatus(SDL_Event* f)
{
	//If mouse event happened
	if (f->type == SDL_MOUSEMOTION || f->type == SDL_MOUSEBUTTONDOWN || f->type == SDL_MOUSEBUTTONUP)
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
		else if (x > mPosition.x + Button_Width)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < mPosition.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > mPosition.y + Button_Height)
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
			switch (f->type)
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

bool SButton::HandleStatus(SDL_Event* g)
{
	bool flag = false;
	getStatus(g);
	switch (status)
	{
	case BUTTON_MOUSE_OUT:
	default:
		new_hover_status = true;
		new_click_status = true;
		Button_Texture.render(mPosition.x, mPosition.y, Button_Width, Button_Height, NULL, 0, NULL, SDL_FLIP_NONE);
			
		break;
	case BUTTON_MOUSE_OVER_MOTION:
		SDL_Rect c;
		c.x = 0;
		c.y = 0;
		c.w = Button_Width;
		c.h = Button_Height;
		Button_Texture.render(mPosition.x - 5, mPosition.y - 5, Button_Width + 10, Button_Height + 10, &c, 0, NULL, SDL_FLIP_NONE);
		if (new_hover_status)
		{
			Hover.Stop();
			if (Mix_PlayingMusic() == 0)
				Hover.Play();
			new_hover_status = false;
		}
		break;

	case BUTTON_MOUSE_DOWN:
		if (new_click_status)
		{
			Click.Stop();
			if (Mix_PlayingMusic() == 0)
				Click.Play();
			SDL_Delay(100);
			Click.Stop();
			new_click_status = false;
			flag = true;

		}
		
		break;
	}
	return flag;
}

LButtonFunction SButton::return_status(void)
{
	return status;
}
bool SButton::return_new_hover_status(void)
{
	return new_hover_status;
}

