#pragma once

#include "../Library/SceneBase.h"

class Game;

class PlayScene : public SceneBase
{
private:

    Game* game;

public:

    PlayScene();
    ~PlayScene();

    void Update() override;
    void Draw() override;
};