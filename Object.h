/*
    Класс-родитель объектов
    Пакман
    Кулаков Д.С. ИВТ-13БО
*/

#pragma once

class Object
{
    public:
<<<<<<< HEAD
        int getX();
        int getY();
        int getWidth();
        int getHeight();
=======
        virtual int getX() = 0;
        virtual int getY() = 0;
        virtual void setX(int x);
        virtual void setY(int y);
        virtual void setWidth(int width);
        virtual void setHeight(int height);
>>>>>>> 16f48f15ac9829323799cf2e1742fad86b005a60
    protected:
        //координаты
        int _x, _y;
        int _width, _height;
};