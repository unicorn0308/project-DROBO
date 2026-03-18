#include "Switch.h"
#include <DxLib.h>

Switch::Switch() :Object2D(), x(0), y(0), hImage(-1)
{
    x = 500;
    y = 500;
	hImage = LoadGraph("Image/switch.png");

    r = 255;
    g = 255;
    b = 255;
}

void Switch::SetColor(int red, int green, int blue)
{
    r = red;
    g = green;
    b = blue;
}

void Switch::Draw()
{
    SetDrawBright(r, g, b);
    DrawGraph(x, y, hImage, TRUE);
    SetDrawBright(255, 255, 255);
}

int Switch::GetX()
{
    return x;
}

int Switch::GetY()
{
    return y;
}
void Switch::SetPosition(int px, int py)
{
    x = px;
    y = py;
}

void Switch::SetTarget(int id)
{
    targetID = id;
}

int Switch::GetTarget()
{
    return targetID;
}