#include "Game.h"
#include "Player.h"
#include "Laser.h"
#include "Switch.h"
#include "Door.h"
#include <DxLib.h>
#include "../Library/SceneManager.h"

Game::Game()
{
    stage = 1;
    player = new Player();
    laser = new Laser();
    sw = new Switch();
    door = new Door();

    isDead = false;
}

Game::~Game()
{
   
}

void Game::Update()
{
    int switchX, switchY;
    int laserX;
    int doorX, doorY;

    // ステージごとの配置
    if (stage == 1)
    {
        switchX = 300;
        switchY = 320;
        laserX = 500;
        doorX = 800;
        doorY = 300;
    }
    else if (stage == 2)
    {
        switchX = 200;
        switchY = 200;
        laserX = 600;
        doorX = 1000;
        doorY = 250;
    }
    else
    {
        switchX = 400;
        switchY = 350;
        laserX = 700;
        doorX = 1200;
        doorY = 200;
    }

    // 各オブジェクトに位置セット
    sw->SetPosition(switchX, switchY);
    laser->SetPosition(laserX);
    door->SetPosition(doorX, doorY);

    player->Update();

    // スイッチ
    if (player->Hit(switchX, switchY, 32, 32))
    {
        laser->Off();
    }

    // レーザー死亡
    if (!laser->IsOff())
    {
        if (player->Hit(laserX, 0, 16, 480))
        {
            isDead = true;
        }
    }

    // 死亡処理
    if (isDead)
    {
        SceneManager::ChangeScene("GAMEOVER");
    }

    // ゴール
    if (player->Hit(doorX, doorY, 40, 60))
    {
        stage++;

        if (stage > 3)
        {
            SceneManager::ChangeScene("RESULT");
        }
        else
        {
            ResetStage();
        }
    }
}

void Game::Draw()
{
    sw->Draw();
    laser->Draw();
    door->Draw();
    player->Draw();

    DrawFormatString(20, 20, GetColor(255, 255, 255), "STAGE %d", stage);
}

void Game::ResetStage()
{
    player->SetPosition(100, 300);
    laser->On();   // ←ここ重要（ONに戻す）
    isDead = false;
}