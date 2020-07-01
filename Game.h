/*
    Основной класс управления игры
    Пакман
    Кулаков Д.С. ИВТ-13БО
*/

#include <SDL.h>
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
        int getScreenHeight();
        int getScreenWidth();

    private:
        //Загрузка текстуры
        SDL_Texture* LoadTexture(std::string BMP_path);
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