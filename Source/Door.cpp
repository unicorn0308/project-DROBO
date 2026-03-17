#include "Door.h"
#include <DxLib.h>

Door::Door() :Object2D(), x(0), y(0), hImage(-1)
{
    x = 1500;
    y = 900;
	hImage = LoadGraph("Image/door.png");
}

void Door::Draw()
{
	DrawGraph(x, y, hImage, TRUE);
}

int Door::GetX()
{
    return x;
}

int Door::GetY()
{
    return y;
}
void Door::SetPosition(int px,int py)
{
    x = px;
	y = py;
}