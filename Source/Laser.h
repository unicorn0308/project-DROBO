#pragma once

class Laser
{
private:

    int x;
    bool off;

public:

    Laser();

    void Draw();

    void Off();
    bool IsOff();

    int GetX();
};