#pragma once
#include "GameEntity.h"
class Bubble :
    public GameEntity
{
public:
    Bubble();
    void setupBody();
    void spawn(sf::Vector2f t_pos);
    void move();
    sf::CircleShape getBody();

private:
    sf::CircleShape m_body;
    float m_speed;
};

