#include "ResultScene.h"
#include <DxLib.h>
#include "../Library/SceneManager.h"

ResultScene::ResultScene()
{
	resultImg = LoadGraph("Image/gameclear.jpg");
}

ResultScene::~ResultScene()
{
}

void ResultScene::Update()
{

    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        SceneManager::ChangeScene("TITLE");
    }
}

void ResultScene::Draw()
{
    int imgW, imgH;
    GetGraphSize(resultImg, &imgW, &imgH);

    int screenW = 1920;
    int screenH = 1080;

    int x = (screenW - imgW) / 2;
    int y = (screenH - imgH) / 2;

    DrawGraph(x, y, resultImg, TRUE);

    SetFontSize(40);
    DrawString(700, 900, "スペースでタイトルに戻る", GetColor(255, 255, 255));
}
