#include "Game.h"
#include "Player.h"
#include "Laser.h"
#include "Switch.h"
#include "Door.h"
#include "../Library/SceneManager.h"

Game::Game()
{
    player = new Player();
    laser = new Laser();
    sw = new Switch();
    door = new Door();
}

Game::~Game()
{
    delete player;
    delete laser;
    delete sw;
    delete door;
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
            SceneManager::ChangeScene("TITLE");
        }
    }

    if (player->Hit(door->GetX(), door->GetY(), 40, 60))
    {
        SceneManager::ChangeScene("TITLE");
    }
}



void Game::Draw()
{
    player->Draw();
    laser->Draw();
    sw->Draw();
    door->Draw();

}