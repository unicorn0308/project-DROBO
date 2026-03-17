#include "Game.h"
#include "Player.h"
#include "Laser.h"
#include "Switch.h"
#include "Door.h"
#include <DxLib.h>
#include "../Library/SceneManager.h"

Game::Game()
{
    player = new Player();
    laser = new Laser();
    sw = new Switch();
	door = new Door();
	laserOff = false;
	isDead = false;
}

Game::~Game()
{
  
}

void Game::Update()
{
    player->Update();

    if (player->Hit(sw->GetX(), sw->GetY(), 32, 32))
    {
        laser->Off();
    }

    if (!laser->IsOff())
    {
        if (player->Hit(laser->GetX(), 0, 16, 480))
        {
			isDead = true;
            SceneManager::ChangeScene("GAMEOVER");
        }
    }

    if (player->Hit(door->GetX(), door->GetY(), 40, 60))
    {
        SceneManager::ChangeScene("RESULT");
    }
}

void Game::Draw()
{
    sw->Draw();
    laser->Draw();
    door->Draw();
    player->Draw();
}