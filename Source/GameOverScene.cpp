#include "GameOverScene.h"

GameOverScene::GameOverScene()
{
	gameOverImg = LoadGraph("Image/gameover.jpg");
	if (gameOverImg == -1)
	{
		printfDx("ゲームオーバー画像ロード失敗\n");
	}
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		SceneManager::ChangeScene("TITLE");
	}
}

void GameOverScene::Draw()
{
	int imgW, imgH;
	GetGraphSize(gameOverImg, &imgW, &imgH);

	int screenW = 1920;
	int screenH = 1080;

	int x = (screenW - imgW) / 2;
	int y = (screenH - imgH) / 2;
	DrawGraph(x,y, gameOverImg, TRUE);
	DrawString(700, 900, "スペースでタイトルに戻る", GetColor(255, 255, 255));
}
