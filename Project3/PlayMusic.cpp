#include "PlayMusic.h"



PlayMusic::PlayMusic()
{
    //ctor
}

PlayMusic::~PlayMusic()
{
    //dtor
}

PlayMusic::PlayMusic(Mix_Music* p):sound(p)
{
    if( sound == NULL )
	{
		std::cout<<"Failed to load sound effect! SDL_mixer Error:"<< Mix_GetError();
	}
}
void PlayMusic::setsound(Mix_Music* p)
{
	sound = p;
	if (sound == NULL)
	{
		std::cout << "Failed to load sound effect! SDL_mixer Error:" << Mix_GetError();
	}
}

void PlayMusic::Play()
{
	Mix_HaltMusic();
    //If there is no           music playing
        if( Mix_PlayingMusic() == 0 )
		{
            //Play the music
                Mix_PlayMusic( sound, -1 );
		}
    //If music is being played
        else
		{
            //If the music is paused
                if( Mix_PausedMusic() == 1 )
                {
                    //Resume the music
                        Mix_ResumeMusic();
                }
            //If the music is playing
                else
                {
                    //Pause the music
                        Mix_PauseMusic();
                }
				

        }
}

void PlayMusic::Play_ntimes(int i)
{
	//If there is no music playing
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(sound, i);
	}
	//If music is being played
	else
	{
		//If the music is paused
		if (Mix_PausedMusic() == 1)
		{
			//Resume the music
			Mix_ResumeMusic();
		}
		//If the music is playing
		else
		{
			//Pause the music
			Mix_PauseMusic();
		}
	}
}


void PlayMusic::Stop()
{
    Mix_HaltMusic();
}



