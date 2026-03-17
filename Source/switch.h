#pragma once
#include "Object2D.h"

class Switch : public Object2D
{
private:

    int x;
    int y;
    int hImage;

public:

    Switch();

    void Draw();

    int GetX();
    int GetY();
};