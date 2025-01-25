#pragma once
#include "GameEntity.h"
#include "Bubble.h"

class Geiser :
    public GameEntity
{
public:
    void setupBody(sf::Vector2f t_pos);
    sf::CircleShape getBubble();
    sf::FloatRect getBubbleBounds();
    void moveBubble();
    void disableBubble();
private:
    Bubble bubble;
};

