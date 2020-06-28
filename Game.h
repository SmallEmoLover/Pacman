/*
    Основной класс управления игры
    Пакман
    Кулаков Д.С. ИВТ-13БО
*/

#include <SDL.h>

class Game
{
    public:
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
		SDL_Window *getGameWindow();

    private:
        int ScreenHeight, ScreenWidth;
        //Кол-во жизней
        int Life;
        //Кол-во очков
        int Score;
        //Текущий уровень
        int Level;
        //Окно игры
		SDL_Window* GameWindow;
};