#include "Game.h"
#include "Cat.h"
#include "Wall.h"
#include "Player.h"
#include "Util.h"
#include "Rubbish.h"
#include <stdio.h>

Game::Game()
{
	_Life = 3;
	_Score = 0;
	_Level = 1;
	_ScreenHeight = 576;
	_ScreenWidth = 448;
	_GameRanderer = NULL;
	_GameWindow = NULL;
}

SDL_Texture* LoadTexture(std::string BMP_path)
{
	//Загрузка изображения
	SDL_Surface* srf = SDL_LoadBMP(BMP_path);
	if (srf == NULL)
	{
		printf("Can`t open file %s", BMP_path);
		return NULL;
	}
	//Цвет, который будет "прозрачным" при рендеринге
	//SDL_SetColorKey(srf, SDL_TRUE, SDL_MapRGB(srf->format, 255, 255, 255));
	SDL_Texture* texture = NULL;
	texture = SDL_CreateTextureFromSurface(_GameRanderer, srf);
	if (texture == NULL)
		printf("Can`t load texture %s", BMP_path);
	SDL_FreeSurface(srf);

	return texture;
}

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
	//Инициализация рендерера
	_GameRanderer = SDL_CreateRenderer(_GameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_GameRanderer == NULL)
		printf("Renderer creation error - %s", SDL_GetError());
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
					printf("Up\n");
				if (event.key.keysym.sym == SDLK_DOWN)
					printf("Down\n");
				if (event.key.keysym.sym == SDLK_LEFT)
					printf("Left\n");
				if (event.key.keysym.sym == SDLK_RIGHT)
					printf("Right\n");
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

void Game::ShowObject(Object *object, SDL_Texture *texture, int width, int height)
{
	SDL_Rect sizes;
	sizes.x = object->getX() - ((width - object->getWidth()) / 2);
	sizes.y = object->getY() - ((height - object->getHeight()) / 2);
	sizes.w = width;
	sizes.h = height;

	SDL_RenderCopy(_GameRanderer, texture, NULL, &sizes);
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

//Очищаем ресурсы
void Game::Exit()
{
	SDL_DestroyRenderer(_GameRanderer);
	SDL_DestroyWindow(_GameWindow);
	SDL_Quit();
}