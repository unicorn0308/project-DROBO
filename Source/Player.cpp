#include "Player.h"
#include <DxLib.h>

Player::Player()
{
     x = 100;
     y = 300;
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
    DrawBox(x, y, x + 32, y + 32, GetColor(0, 0, 255), TRUE);
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