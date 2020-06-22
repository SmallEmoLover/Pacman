/*
    Основной класс управления игры
    Пакман
    Кулаков Д.С. ИВТ-13БО
*/

class Game
{
    public:
        //Инициализация отображения
        //TODO: Подумать над засовыванием инициализации в конструктор
        void Initialize();
        //Старт игры
        void Start();
        //Пауза
        void Pause();
        //Продолжение
        void Resume();
        //Выход
        void Exit();
        int getScreenHeight();
        int getScreenWidth();
    private:
        int ScreenHeight, ScreenWidth;
        //Кол-во жизней
        int Life;
        //Кол-во очков
        int Score;
        //Текущий уровень
        int Level;
};