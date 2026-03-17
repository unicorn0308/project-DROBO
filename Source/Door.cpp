#include "Door.h"
#include <DxLib.h>

Door::Door()
{
    x = 1500;
    y = 900;
}

void Door::Draw()
{
    DrawBox(x, y, x + 40, y + 60, GetColor(0, 255, 0), TRUE);
}

int Door::GetX()
{
    return x;
}

int Door::GetY()
{
    return y;
}