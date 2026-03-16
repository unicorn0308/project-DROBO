#include "TitleScene.h"
#include "../Library/SceneManager.h"
#include <DxLib.h>

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
    // Pキーでゲーム開始
    if (CheckHitKey(KEY_INPUT_P))
    {
        SceneManager::ChangeScene("GAME");
    }

    // ESCキーで終了
    if (CheckHitKey(KEY_INPUT_ESCAPE))
    {
        SceneManager::Exit();
    }
}

void TitleScene::Draw()
{
    DrawString(300, 150, "ESCAPE ROBOT GAME", GetColor(255, 255, 255));

    DrawString(260, 300, "Push [P] Key To Play", GetColor(255, 255, 255));
    DrawString(260, 340, "Push [ESC] Key To Exit", GetColor(255, 255, 255));
}