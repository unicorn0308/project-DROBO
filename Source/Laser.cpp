#include "Laser.h"
#include <DxLib.h>

Laser::Laser() :Object2D(), x(0), hImage(-1), off(false)
{
    x = 1000;
	hImage = LoadGraph("Image/laser.png");
    off = false;
}

void Laser::Draw()
{
	for (int i = 0; i < 1080 / 128; i++)//縦に16ピクセルのレーザーを描画
    {
        if (!off)
        {
            DrawGraph(x,i*128, hImage, TRUE);
        }
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
 void Laser::On()
{
     off = false;
  }



void Laser::SetPosition(int px )
{
    x = px;
   
}


void Laser::SetID(int i)
{
    id = i;
}

int Laser::GetID()
{
    return id;
}