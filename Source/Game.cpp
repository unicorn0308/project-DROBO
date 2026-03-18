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

    
        lasers1 = new Laser();
        switches1 = new Switch();

        lasers2 = new Laser();
        switches2 = new Switch();
  
        laser->SetColor(255, 0, 0);     // 赤
        lasers1->SetColor(0, 255, 0);   // 緑
        lasers2->SetColor(0, 0, 255);   // 青

        sw->SetColor(255, 0, 0);        // 赤スイッチ → 赤レーザー
        switches1->SetColor(0, 255, 0); // 緑スイッチ → 緑レーザー
        switches2->SetColor(0, 0, 255); // 青スイッチ → 青レーザー


    isDead = false;
}

Game::~Game()
{
   
}

void Game::Update()
{
    int switchX{}, switchY{};
	
    int laserX{};
	
    int doorX{}, doorY{};

    // ステージごとの配置
    if (stage == 1)
    {
        // スイッチ1個
        switchX = 300;
        switchY = 320;

        laserX = 500;
        doorX = 800;
        doorY = 300;

        // 使わないやつは画面外へ
        switches1->SetPosition(-100, -100);
        lasers1->SetPosition(-100);

        switches2->SetPosition(-100, -100);
        lasers2->SetPosition(-100);
    }
    else if (stage == 2)
    {
        // スイッチ2個
        switchX = 300;
        switchY = 320;

        laserX = 500;

        doorX = 1000;
        doorY = 250;

        // 2個目を配置
        switches1->SetPosition(500, 200);
        lasers1->SetPosition(800);

        // 3個目はまだ使わない
        switches2->SetPosition(-100, -100);
        lasers2->SetPosition(-100);
    }
    else if (stage == 3)
    {
        // スイッチ3個
        switchX = 300;
        switchY = 320;

        laserX = 500;

        doorX = 1200;
        doorY = 200;

        // 2個目
        switches1->SetPosition(500, 200);
        lasers1->SetPosition(800);

        // 3個目
        switches2->SetPosition(900, 300);
        lasers2->SetPosition(1100);


        

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

    // スイッチ2
    if (player->Hit(switches1->GetX(), switches1->GetY(), 32, 32))
    {
        lasers1->Off(); // ← 対応するレーザーを消す

    }
    // スイッチ3 
    if (player->Hit(switches2->GetX(), switches2->GetY(), 32, 32))
    {
        lasers2->Off();
    }

    // レーザー
    laser->SetID(0);
    lasers1->SetID(1);
	lasers2->SetID(2);

    
    sw->SetTarget(1); // ←レーザー1を消す
    switches1->SetTarget(0); // ←レーザー0を消す
	switches2->SetTarget(2); // ←レーザー2を消す

    // レーザー死亡
    if (!laser->IsOff())
    {
        if (player->Hit(laserX, 0, 16, 480))
        {
            isDead = true;
        }
    }

    if (!lasers1->IsOff())
{
    if (player->Hit(lasers1->GetX(), 0, 16, 480))
    {
        SceneManager::ChangeScene("GAMEOVER");
    }
}
    if (!lasers2->IsOff())
    {
        if (player->Hit(lasers2->GetX(), 0, 16, 480))
        {
            SceneManager::ChangeScene("GAMEOVER");
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

    switches1->Draw();
    lasers1->Draw();

    switches2->Draw();   //
    lasers2->Draw();     // 

    DrawFormatString(20, 20, GetColor(255, 255, 255), "STAGE %d", stage);
}

void Game::ResetStage()
{
    player->SetPosition(100, 300);
    laser->On();// ←ここ重要（ONに戻す）
    lasers1->On();
    lasers2->On();
    isDead = false;
}