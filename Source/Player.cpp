#include "Player.h"
#include <DxLib.h>

Player::Player() :Object2D(), game(nullptr), x(0), y(0), hImage(-1)
{
     x = 100;
     y = 300;
	 hImage = LoadGraph("Image/player.png");
}

Player::~Player()
{
}

void Player::Update()
{
    if (CheckHitKey(KEY_INPUT_LEFT)) x -= 4;
    if (CheckHitKey(KEY_INPUT_RIGHT)) x += 4;
    if (CheckHitKey(KEY_INPUT_UP)) y -= 4;
    if (CheckHitKey(KEY_INPUT_DOWN)) y += 4;
}

void Player::Draw()
{
	DrawGraph(x, y, hImage, TRUE);
}

void Player::SetPosition(int px, int py)
{
    x = px;
    y = py;
}

bool Player::Hit(int ox, int oy, int w, int h)
{
    if (x + 32 > ox && x < ox + w &&
        y + 32 > oy && y < oy + h)
    {
        return true;
    }

    return false;
}

