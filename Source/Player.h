#pragma once

#include "../Library/GameObject.h"

class Game;

class Player : public GameObject
{
private:

    Game* game;
	int x;
	int y;
   

public:

    Player();
    ~Player();

    void Update() override;
    void Draw() override;


    bool Hit(int ox, int oy, int w, int h);

};