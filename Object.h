/*
    Абстрактный класс-родитель объектов
    Пакман
    Кулаков Д.С. ИВТ-13БО
*/

#pragma once

class Object
{
    public:
        virtual int getX() = 0;
        virtual int getY() = 0;
        virtual void setX(int x);
        virtual void setY(int y);
        virtual void setWidth(int width);
        virtual void setHeight(int height);
    protected:
        //координаты
        int _x, _y;
        int _width, _height;
};