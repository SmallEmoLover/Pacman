#include "Game.h"
#include <stdio.h>

void Game::Initialize()
{
    //Инициализация SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("Init error - %s", SDL_GetError());
	else
	{
        //Инициализация окна
		_GameWindow = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			 _ScreenWidth, _ScreenHeight, SDL_WINDOW_SHOWN);
		if (_GameWindow == NULL)
			printf("Window creation error - %s", SDL_GetError());
	}
}

void Game::Start()
{
	bool quit = false;

	while (quit == false)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_UP)
				{
					printf("Up\n");
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					printf("Down\n");
				}
				if (event.key.keysym.sym == SDLK_LEFT)
				{
					printf("Left\n");
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					printf("Right\n");
				}
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					Pause();
					printf("Pause\n");
				}

			}

			if (event.type == SDL_QUIT)
				quit = true;
		}
	}
	Exit();
}

void Game::Pause()
{
	while (true)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
				return;
		}
	}

}

SDL_Window* Game::getGameWindow()
{
	return _GameWindow;
}

int Game::getScreenHeight()
{
	return _ScreenHeight;
}

int Game::getScreenWidth()
{
	return _ScreenWidth;
}

//Очищаем ресурсы
void Game::Exit()
{
	SDL_FreeSurface(SDL_GetWindowSurface(_GameWindow));
	SDL_DestroyWindow(_GameWindow);
	SDL_Quit();
}