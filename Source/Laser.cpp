#include "Laser.h"
#include <DxLib.h>

Laser::Laser()
{
    x = 350;
    off = false;
}

void Laser::Draw()
{
    if (!off)
    {
        DrawBox(x, 0, x + 16, 480, GetColor(255, 0, 0), TRUE);
    }
}

void Laser::Off()
{
    off = true;
}

bool Laser::IsOff()
{
    return off;
}

int Laser::GetX()
{
    return x;
}