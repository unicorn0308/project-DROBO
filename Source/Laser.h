#pragma once
#include "Object2D.h"

class Laser : public Object2D
{
private:

    int x;
    int hImage;
    bool off;

public:

    Laser();

    void Draw();

    void Off();
    bool IsOff();

    int GetX();
};