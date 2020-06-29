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
        int _ScreenHeight, _ScreenWidth;
        //Кол-во жизней
        int _Life;
        //Кол-во очков
        int _Score;
        //Текущий уровень
        int _Level;
        //Окно игры
		SDL_Window* _GameWindow;
};