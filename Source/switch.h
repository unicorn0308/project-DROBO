#pragma once
#include "Object2D.h"

class Switch : public Object2D
{
private:

    int x;
    int y;
    int hImage;

public:

    Switch();

    void Draw();
	void SetPosition(int x, int y);
    int GetX();
    int GetY();
};