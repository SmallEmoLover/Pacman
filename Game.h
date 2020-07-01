/*
	Основной класс управления игры
	Пакман
	Кулаков Д.С. ИВТ-13БО
*/

#include <SDL.h>
#include <SDL_ttf.h>
#include "Wall.h"
#include <iostream>

class Game
{
public:
	Game();
	//Инициализация отображения
	void Initialize();
	//Старт игры
	void Start();
	//Пауза
	void Pause();
	//Выход
	void Exit();

private:
	void ShowObject(Object *object, SDL_Texture *texture, int width, int height);
	//Загрузка текстуры
	SDL_Texture* LoadTexture(std::string BMP_path);
	//Загрузка текста
	SDL_Texture* LoadText(std::string text, TTF_Font *font);
	//Размеры экрана
	int _ScreenHeight, _ScreenWidth;
	//Кол-во жизней
	int _Life;
	//Кол-во очков
	int _Score;
	//Окно игры
	SDL_Window* _GameWindow;
	//Рендер
	SDL_Renderer* _GameRanderer;
};