/*
    Класс-родитель объектов
    Пакман
    Кулаков Д.С. ИВТ-13БО
*/

#pragma once
#define PixInBlock 16

class Object
{
    public:
        int getX();
        int getY();
        int getWidth();
        int getHeight();
    protected:
        //координаты
        int _x, _y;
        int _width, _height;
};