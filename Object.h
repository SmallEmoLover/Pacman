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
        virtual void setWidth() = 0;
        virtual void setHeight() = 0;
    protected:
        //координаты
        int x, y;
        int width, height;
};