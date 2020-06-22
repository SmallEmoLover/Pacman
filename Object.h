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
        virtual int setWidth() = 0;
        virtual int setHeight() = 0;
    private:
        //координаты
        int x, y;
        int width, height;
};