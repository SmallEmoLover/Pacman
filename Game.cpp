#include "Game.h"
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
	SDL_Texture *MapTexture = LoadTexture("textures/kover.bmp");
	SDL_Texture *PlayerTexture = LoadTexture("textures/NormalPlayer.bmp");
	SDL_Texture *EnemyTexture = LoadTexture("textures/Enemy.bmp");
	SDL_Texture *RubbishTexture = LoadTexture("textures/Rubbish.bmp");
	SDL_Texture *Score = NULL;

	//Инициализация игровых объектов
	Player *player = new Player();
	Cat *cat = new Cat(14, 14);
	Wall *walls[WallCount];
	CreateWalls(walls);
	Rubbish *rubbish[RubbishCount];
	CreateRubbish(walls, rubbish);

	//Инициализация расположения текста
	SDL_Rect Score_rect;
	Score_rect.x = 0;
	Score_rect.y = 0;
	Score_rect.w = 15 * PixInBlock;
	Score_rect.h = 2 * PixInBlock;

	//Инициализация расположения жизней
	SDL_Rect Lives_rect;
	Lives_rect.y = 34 * PixInBlock;
	Lives_rect.w = 2 * PixInBlock;
	Lives_rect.h = 2 * PixInBlock;

	std::string ScoreText;

	//Направление, в которое нужно повернуть в следующем повороте
	way direction = LEFT;

	//Количество оставшихся элементов
	int RubbishLeft = RubbishCount;

	//Флаг выхода
	bool quit = false;
	while (quit == false)
	{
		Score = LoadText("Score: " + std::to_string(_Score), font);
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
			Score = LoadText("Level passed", font);

			//Перемещаем всё на свои места
			cat->setX(14 * PixInBlock);
			cat->setY(14 * PixInBlock);
			player->setX(14 * PixInBlock);
			player->setY(26 * PixInBlock);
			for (int i = 0; i < RubbishCount; i++)
				rubbish[i]->setIsCollected(false);
			RubbishLeft = RubbishCount;

			//Показываем всё
			SDL_RenderCopy(_GameRanderer, MapTexture, NULL, NULL);
			SDL_RenderCopy(_GameRanderer, Score, NULL, &Score_rect);
			for (int i = 0; i < RubbishCount; i++)
				if (rubbish[i]->getIsCollected() == false)
					ShowObject(rubbish[i], RubbishTexture, 10, 10);
			ShowObject(player, PlayerTexture, 32, 32);
			ShowObject(cat, EnemyTexture, 40, 40);
			SDL_RenderPresent(_GameRanderer);

			Pause();
		}

		//Если нас задели
		if (CollisionDetect(player, cat))
		{
			//Перемещаем всё на свои места
			cat->setX(14 * PixInBlock);
			cat->setY(14 * PixInBlock);
			player->setX(14 * PixInBlock);
			player->setY(26 * PixInBlock);
			direction = LEFT;

			if (_Life == 0)
			{
				Score = LoadText("You lose!", font);
				_Score = 0;
				_Life = 3;
				for (int i = 0; i < RubbishCount; i++)
					rubbish[i]->setIsCollected(false);
			}
			else
			{
				Score = LoadText("Press any key", font);
				_Life--;
			}

			SDL_RenderCopy(_GameRanderer, MapTexture, NULL, NULL);
			SDL_RenderCopy(_GameRanderer, Score, NULL, &Score_rect);
			for (int i = 0; i < RubbishCount; i++)
				if (rubbish[i]->getIsCollected() == false)
					ShowObject(rubbish[i], RubbishTexture, 10, 10);
			ShowObject(player, PlayerTexture, 32, 32);
			ShowObject(cat, EnemyTexture, 40, 40);
			SDL_RenderPresent(_GameRanderer);

			Pause();
		}

		//Если в том направлении, куда мы хотим, нет стен, то направляемся туда
		if (!IsWall(player, walls, direction))
			player->setDirection(direction);

		//Двигаем объекты
		player->move(walls);
		cat->AIMove(player->getX(), player->getY(), 2, walls);

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
						Pause();
						break;
				}
			}

			if (event.type == SDL_QUIT)
				quit = true;
		}


		//Загрузка текстур
		SDL_RenderCopy(_GameRanderer, MapTexture, NULL, NULL);
		SDL_RenderCopy(_GameRanderer, Score, NULL, &Score_rect);
		for (int i = 0; i < RubbishCount; i++)
			if (rubbish[i]->getIsCollected() == false)
				ShowObject(rubbish[i], RubbishTexture, 10, 10);
		ShowObject(player, PlayerTexture, 32, 32);
		ShowObject(cat, EnemyTexture, 40, 40);
		for (int i = 0; i < _Life; i++)
		{
			Lives_rect.x = i * PixInBlock;
			SDL_RenderCopy(_GameRanderer, PlayerTexture, NULL, &Lives_rect);
		}


		//Рендеринг
		SDL_RenderPresent(_GameRanderer);
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
			if (event.type == SDL_KEYDOWN)
				return;
		}
	}

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
	SDL_DestroyRenderer(_GameRanderer);
	SDL_DestroyWindow(_GameWindow);
	SDL_Quit();
}