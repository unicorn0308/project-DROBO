#pragma once

#include "Object2D.h"

class Game;

class Player : public Object2D
{
private:

    Game* game;
	int x;
	int y;
    int hImage;
   

public:

    Player();
    ~Player();

    void Update() override;
    void Draw() override;


    bool Hit(int ox, int oy, int w, int h);

	int GetX() { return x; }
	int GetY() { return y; }

};