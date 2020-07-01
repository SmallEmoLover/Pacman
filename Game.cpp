/*
	Реализация класса управления игры
	Пакман
	Кулаков Д.С. ИВТ-13БО
*/

#include "Game.h"
#include <stdio.h>
#include <SDL_ttf.h>
#include <string>
#include "Util.h"

Game::Game()
{
	_Life = 3;
	_Score = 0;
	_ScreenHeight = 36 * PixInBlock;
	_ScreenWidth = 28 * PixInBlock;
	_GameRanderer = NULL;
	_GameWindow = NULL;
}

SDL_Texture* Game::LoadTexture(std::string BMP_path)
{
	//Загрузка изображения
	SDL_Surface* srf = SDL_LoadBMP(BMP_path.c_str());
	//Цвет, который будет "прозрачным" при рендеринге
	SDL_SetColorKey(srf, SDL_TRUE, SDL_MapRGB(srf->format, 255, 255, 255));

	SDL_Texture* texture = NULL;
	texture = SDL_CreateTextureFromSurface(_GameRanderer, srf);
	SDL_FreeSurface(srf);

	return texture;
}

void Game::Initialize()
{
	//Инициализация SDL
	SDL_Init(SDL_INIT_VIDEO);
	//Инициализация окна
	_GameWindow = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		_ScreenWidth, _ScreenHeight, SDL_WINDOW_SHOWN);
	//Инициализация рендерера
	_GameRanderer = SDL_CreateRenderer(_GameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//Инициализация работы со шрифтами
	TTF_Init();
}

void Game::Start()
{
	//Загрузка шрифта
	TTF_Font *font = TTF_OpenFont("textures/font.ttf", 80);

	//Загрузка текстур
	SDL_Texture *MapTexture = LoadTexture("textures/Background.bmp");
	SDL_Texture *PlayerTexture = LoadTexture("textures/Player.bmp");
	SDL_Texture *RedCatTexture = LoadTexture("textures/RedCat.bmp");
	SDL_Texture *BlackCatTexture = LoadTexture("textures/BlackCat.bmp");
	SDL_Texture *RubbishTexture = LoadTexture("textures/Rubbish.bmp");
	SDL_Texture *Text = NULL;

	//Инициализация игровых объектов
	Player *player = new Player();
	Cat *redCat = new Cat(9, 14);
	Cat *blackCat = new Cat(14, 14);
	Wall *walls[WallCount];
	CreateWalls(walls);
	Rubbish *rubbish[RubbishCount];
	CreateRubbish(walls, rubbish);

	//Инициализация расположения текста
	SDL_Rect Text_rect;
	Text_rect.x = 0;
	Text_rect.y = 0;
	Text_rect.w = 20 * PixInBlock;
	Text_rect.h = 2 * PixInBlock;

	std::string ScoreText;

	//Инициализация расположения жизней
	SDL_Rect Lives_rect;
	Lives_rect.y = 34 * PixInBlock;
	Lives_rect.w = 2 * PixInBlock;
	Lives_rect.h = 2 * PixInBlock;

	//Направление, в которое нужно повернуть в следующем повороте
	way direction = LEFT;

	//Количество оставшихся элементов
	int RubbishLeft = RubbishCount;

	//Флаг выхода
	bool quit = false;
	while (quit == false)
	{
		//Красивый счёт
		int temp = _Score;
		int rank = 0;
		while (temp != 0)
		{
			temp /= 10;
			rank++;
		}
		ScoreText = "Score ";
		for (int i = 0; i < 8 - rank; i++)
			ScoreText += "0";
		ScoreText += std::to_string(_Score);

		SDL_DestroyTexture(Text);
		Text = LoadText(ScoreText, font);

		for (int i = 0; i < RubbishCount; i++)
		{
			if (rubbish[i]->getIsCollected() == false && CollisionDetect(rubbish[i], player))
			{
				rubbish[i]->setIsCollected(true);
				RubbishLeft--;
				_Score += 50;
			}
		}
		
		//Если собрано всё
		if (RubbishLeft <= 0)
		{
			_Score += 1000;
			direction = LEFT;
			SDL_DestroyTexture(Text);
			Text = LoadText("Level passed", font);

			//Перемещаем всё на свои места
			redCat->setX(9 * PixInBlock);
			redCat->setY(14 * PixInBlock);
			blackCat->setX(14 * PixInBlock);
			blackCat->setY(14 * PixInBlock);
			player->setX(14 * PixInBlock);
			player->setY(26 * PixInBlock);
			for (int i = 0; i < RubbishCount; i++)
				rubbish[i]->setIsCollected(false);
			RubbishLeft = RubbishCount;

			//Показываем всё
			SDL_RenderCopy(_GameRanderer, MapTexture, NULL, NULL);
			SDL_RenderCopy(_GameRanderer, Text, NULL, &Text_rect);
			for (int i = 0; i < RubbishCount; i++)
				if (rubbish[i]->getIsCollected() == false)
					ShowObject(rubbish[i], RubbishTexture, 10, 10);
			ShowObject(player, PlayerTexture, 32, 32);
			ShowObject(redCat, RedCatTexture, 40, 40);
			ShowObject(blackCat, BlackCatTexture, 40, 40);
			SDL_RenderPresent(_GameRanderer);

			Pause();
		}

		//Если нас задели
		if (CollisionDetect(player, redCat) || CollisionDetect(player, blackCat))
		{
			//Перемещаем всё на свои места
			redCat->setX(9 * PixInBlock);
			redCat->setY(14 * PixInBlock);
			blackCat->setX(14 * PixInBlock);
			blackCat->setY(14 * PixInBlock);
			player->setX(14 * PixInBlock);
			player->setY(26 * PixInBlock);
			direction = LEFT;
			SDL_DestroyTexture(Text);

			if (_Life == 0)
			{
				Text = LoadText("You lose!", font);
				_Score = 0;
				_Life = 3;
				for (int i = 0; i < RubbishCount; i++)
					rubbish[i]->setIsCollected(false);
			}
			else
			{
				Text = LoadText("Press any key", font);
				_Life--;
			}

			SDL_RenderCopy(_GameRanderer, MapTexture, NULL, NULL);
			SDL_RenderCopy(_GameRanderer, Text, NULL, &Text_rect);
			for (int i = 0; i < RubbishCount; i++)
				if (rubbish[i]->getIsCollected() == false)
					ShowObject(rubbish[i], RubbishTexture, 10, 10);
			ShowObject(player, PlayerTexture, 32, 32);
			ShowObject(redCat, RedCatTexture, 40, 40);
			ShowObject(blackCat, BlackCatTexture, 40, 40);
			SDL_RenderPresent(_GameRanderer);

			Pause();
		}

		//Если в том направлении, куда мы хотим, нет стен, то направляемся туда
		if (!IsWall(player, walls, direction))
			player->setDirection(direction);

		//Двигаем объекты
		player->move(walls);
		redCat->RedMove(player->getX(), player->getY(), 2, walls);
		blackCat->BlackMove(player->getX(), player->getY(), 2, walls);

		//Обрабатываем нажатия на клавиши
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
						direction = UP;
						break;
					case SDLK_DOWN:
						direction = DOWN;
						break;
					case SDLK_LEFT:
						direction = LEFT;
						break;
					case SDLK_RIGHT:
						direction = RIGHT;
						break;
					case SDLK_ESCAPE:
						SDL_DestroyTexture(Text);
						Text = LoadText("Press any key", font);
						SDL_RenderCopy(_GameRanderer, MapTexture, NULL, NULL);
						SDL_RenderCopy(_GameRanderer, Text, NULL, &Text_rect);
						SDL_RenderPresent(_GameRanderer);
						Pause();
						break;
				}
			}

			if (event.type == SDL_QUIT)
				quit = true;
		}


		//Загрузка текстур
		SDL_RenderCopy(_GameRanderer, MapTexture, NULL, NULL);
		SDL_RenderCopy(_GameRanderer, Text, NULL, &Text_rect);
		for (int i = 0; i < RubbishCount; i++)
			if (rubbish[i]->getIsCollected() == false)
				ShowObject(rubbish[i], RubbishTexture, 10, 10);
		ShowObject(player, PlayerTexture, 32, 32);
		ShowObject(redCat, RedCatTexture, 40, 40);
		ShowObject(blackCat, BlackCatTexture, 40, 40);
		for (int i = 0; i < _Life; i++)
		{
			Lives_rect.x = i * PixInBlock * 1.5;
			SDL_RenderCopy(_GameRanderer, PlayerTexture, NULL, &Lives_rect);
		}


		//Рендеринг
		SDL_RenderPresent(_GameRanderer);
	}

	//Очищаем текстуры перед выходои
	SDL_DestroyTexture(MapTexture);
	SDL_DestroyTexture(RedCatTexture);
	SDL_DestroyTexture(BlackCatTexture);
	SDL_DestroyTexture(PlayerTexture);
	SDL_DestroyTexture(RubbishTexture);
	SDL_DestroyTexture(Text);

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

SDL_Texture* Game::LoadText(std::string text, TTF_Font *font)
{
	SDL_Color color;
	color.a = 0; 
	color.b = color.g = color.r = 255;
	SDL_Surface *srf = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(_GameRanderer, srf);
	SDL_FreeSurface(srf);

	return texture;
}


void Game::Pause()
{
	while (true)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN || event.type == SDL_QUIT)
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