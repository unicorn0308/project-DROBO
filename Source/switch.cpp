#include "Switch.h"
#include <DxLib.h>

Switch::Switch()
{
    x = 500;
    y = 500;
}

void Switch::Draw()
{
    DrawBox(x, y, x + 32, y + 32, GetColor(255, 255, 0), TRUE);
}

int Switch::GetX()
{
    return x;
}

int Switch::GetY()
{
    return y;
}