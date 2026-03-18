#pragma once
#include "Object2D.h"

class Laser : public Object2D
{
private:

    int x;
    int hImage;
    bool off;
	int id;
    int color;
    int r, g, b;

public:

    void SetID(int i);   
    int GetID();         


    Laser();

    void Draw();
	void SetPosition(int x);
    void Off();
    void On();  
    bool IsOff();

    int GetX();
    
    void SetColor(int red, int green, int blue);
};