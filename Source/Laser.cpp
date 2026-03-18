#include "Laser.h"
#include <DxLib.h>

Laser::Laser() :Object2D(), x(0), hImage(-1), off(false)
{
    x = 1000;
	hImage = LoadGraph("Image/laser.png");
    off = false;

    r = 255;
    g = 255;
    b = 255;
}

void Laser::Draw()
{
	//for (int i = 0; i < 1080 / 128; i++)//縦に16ピクセルのレーザーを描画
 //   {
 //       if (!off)
 //       {
 //           DrawGraph(x,i*128, hImage, TRUE);
 //       }
 //   }

    if (off) return;

    // ★色設定（デフォルトは白＝そのまま表示）
    SetDrawBright(r, g, b);

    for (int i = 0; i < 1080 / 128; i++)
    {
        DrawGraph(x, i * 128, hImage, TRUE);
    }

    // ★元に戻す（重要！）
    SetDrawBright(255, 255, 255);

}


void Laser::SetColor(int red, int green, int blue)
{
    r = red;
    g = green;
    b = blue;
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