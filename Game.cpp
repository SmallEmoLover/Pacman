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
		GameWindow = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			 ScreenWidth, ScreenWidth, SDL_WINDOW_SHOWN);
		if (GameWindow == NULL)
			printf("Window creation error - %s", SDL_GetError());
	}
}

SDL_Window* Game::getGameWindow()
{
	return GameWindow;
}

int Game::getScreenHeight()
{
	return ScreenHeight;
}

int Game::getScreenWidth()
{
	return ScreenWidth;
}

//Очищаем ресурсы
void Game::Exit()
{
	SDL_FreeSurface(SDL_GetWindowSurface(GameWindow));
	SDL_DestroyWindow(GameWindow);
	SDL_Quit();
}