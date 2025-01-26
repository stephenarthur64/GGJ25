#pragma once
#include "GameEntity.h"
#include "Bubble.h"

class Geiser :
    public GameEntity
{
public:
    void setupBody(sf::Vector2f t_pos);
    void setupSprite(sf::Texture& t_gesier, sf::Texture& t_bubble);
    void setPosition(sf::Vector2f t_pos);

    sf::Sprite getBubbleSprite();
    sf::CircleShape getBubble();
    sf::FloatRect getBubbleBounds();
    void moveBubble();
    void disableBubble();
    void enableBubble();
private:
    Bubble bubble;
};

