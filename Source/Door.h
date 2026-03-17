#pragma once
#include "Object2D.h"

class Door : public Object2D
{
private:

    int x;
    int y;
    int hImage;

public:

    Door();

    void Draw();
	void SetPosition(int x, int y);
    int GetX();
    int GetY();
};