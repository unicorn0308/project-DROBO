#include "PlayScene.h"
#include "Game.h"
#include "../Library/SceneManager.h"
#include <DxLib.h>

PlayScene::PlayScene()
{
    game = new Game();
}

PlayScene::~PlayScene()
{
    delete game;
}

void PlayScene::Update()
{
    game->Update();

    if (CheckHitKey(KEY_INPUT_T))
    {
        SceneManager::ChangeScene("RESULT");
    }
}

void PlayScene::Draw()
{
    game->Draw();
}