#pragma once
#include "Object2D.h"

class Switch : public Object2D
{
private:

    int x;
    int y;
    int hImage;

	int targetID;

    int r, g, b;


public:

    Switch();

    void Draw();
	void SetPosition(int x, int y);
    int GetX();
    int GetY();

	void SetTarget(int id);
	int GetTarget();

    void SetColor(int red, int green, int blue);
};