#include "TitleScene.h"
#include "../Library/SceneManager.h"
#include <DxLib.h>

TitleScene::TitleScene()
{
    titleImg = LoadGraph("Image/title.jpg");

    if (titleImg == -1)
    {
        printfDx("タイトル画像ロード失敗\n");
    }
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
	DrawGraph(0, 0, titleImg, TRUE);
    int fSize = SetFontSize(80);
   DrawString(830, 900, "pでプレイ", GetColor(255, 255, 255),fSize);
    //DrawString(260, 340, "Push [ESC] Key To Exit", GetColor(255, 255, 255));
}