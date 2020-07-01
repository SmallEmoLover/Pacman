/*
    Основной класс управления игры
    Пакман
    Кулаков Д.С. ИВТ-13БО
*/

#include <SDL.h>
#include "Object.h"
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
        //Загрузка текстуры
        SDL_Texture* LoadTexture(std::string BMP_path);
        //Рендеринг объекта на экран
        void ShowObject(Object *object, SDL_Texture *texture, int width, int height);
        //Размеры экрана
        int _ScreenHeight, _ScreenWidth;
        //Кол-во жизней
        int _Life;
        //Кол-во очков
        int _Score;
        //Текущий уровень
        int _Level;
        //Окно игры
		SDL_Window* _GameWindow;
        //Рендер
        SDL_Renderer* _GameRanderer;
};