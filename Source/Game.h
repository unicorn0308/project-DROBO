#pragma once

class Player;
class Laser;
class Switch;
class Door;

class Game
{
private:

    Player* player;
    Laser* laser;
    Switch* sw;
    Door* door;

public:

    Game();
    ~Game();

    void Update();
    void Draw();
};