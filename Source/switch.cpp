#include "Switch.h"
#include <DxLib.h>

Switch::Switch() :Object2D(), x(0), y(0), hImage(-1)
{
    x = 500;
    y = 500;
	hImage = LoadGraph("Image/switch.png");
}

void Switch::Draw()
{
	DrawGraph(x, y, hImage, TRUE);
}

int Switch::GetX()
{
    return x;
}

int Switch::GetY()
{
    return y;
}